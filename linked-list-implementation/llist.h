#ifndef LLIST_H
#define LLIST_H

template<T>
class llist
{
    public:
        llist();
        insert_begin(T);
        push(T);
        insert_pos(int,T);
        sorter();
        delete_pos(int);
        update(int,t);
        searcher(T);
        display();
        reverser();

    private:
        struct node;
};

#endif // LLIST_H
