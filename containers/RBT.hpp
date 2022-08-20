#ifndef RBT_HPP
# define RBT_HPP

namespace ft
{
    template <class Key>
    class RBT
    {
        //RBT properties :
        //1. Red/Black Property: Every node is colored, either red or black.
        //2. Root Property: The root is black.
        //3. Leaf Property: Every leaf (NIL) is black.
        //4. Red Property: If a red node has children then, the children are always black.
        //5. Depth Property: For each node, any simple path from this node to any of its descendant
        //   leaf has the same black-depth (the number of black nodes).

        *RBT parent;
        *RBT left; //child 1
        *RBT right;//child 2
        Key value;
        int color; //1=red  0=black

        RBT(){}

        ~RBT(){}

        /*
          Insert
          1. Find the good path to put the key
          2. Insert it.
          3. If properties violated, fix it
          4. Return a pointer on the root
        */

        *RBT insertion(const Key x)
        {

        }

        void fixInsert()
        {

        }

        /*
          Delete
          1. Search for the key in the rbt
          2. Delete it
          3. Replace it by another key (not understand which one yet)
          4. If properties violated, fix it
          5. Return a pointer on the root
        */

        *RBT deletion(const Key x)
        {

        }

        void fixDeletion()
        {

        }

        *RBT next()
        {

        }

        *RBT prev()
        {

        }
    };
}

#endif