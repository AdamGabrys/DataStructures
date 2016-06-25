//
// Created by Adam on 25.06.2016.
//

#ifndef DS_IMPLEMENTATON_DISJOINTSET_H
#define DS_IMPLEMENTATON_DISJOINTSET_H

template< class T>
class DisjointSet{
private:
    DisjointSet<T>* representative;
    T data;
    int rank;
public:
    DisjointSet(T v): data(v), representative(this), rank(0){}

    int get_rank()const{
      return  rank;
    }

    void set_rank(int rank){
      this->rank = rank;
    }

    T get_data()const{
      return data;
    }

    DisjointSet* get_representative()const{
      return representative;
    }

    void set_representative(DisjointSet* rep){
      representative=rep;
    }

    static DisjointSet* find_set(DisjointSet* x){
      if(x!=x->get_representative())
        x->set_representative(find_set(x->get_representative()));
      return x->get_representative();
    }

    static void merge_sets(DisjointSet* x, DisjointSet* y) {
      DisjointSet *x_rep;
      DisjointSet *y_rep;
      x_rep = DisjointSet::find_set(x);
      y_rep = DisjointSet::find_set(y);
      if (x_rep->get_rank() > y_rep->get_rank())
        y_rep->set_representative(x_rep);
      else
        x_rep->set_representative(y_rep);
      if (x_rep->get_rank() == y_rep->get_rank())
        y_rep->set_rank(y_rep->get_rank() + 1);
    }

};
#endif //DS_IMPLEMENTATON_DISJOINTSET_H
