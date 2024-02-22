/*!
\file
\brief Файл реализаций методов класса RBTree
*/

#include "RBTree.h"

RBTree::RBTree(){
	Worker nil_Worker; 
	nil = new RBNode(nil_Worker, Color::BLACK, nil, nil, nil);
    root = nil;     
}

void RBTree::left_rotate(RBNode *x){
    RBNode *y = x->right_child;
    x->right_child = y->left_child;
    if(y->left_child != nil)
        y->left_child->parent = x;
    y->parent = x->parent; 
    if(x->parent == nil)
        root = y;
    else if(x->parent->left_child == x)
        x->parent->left_child = y;
    else
        x->parent->right_child = y;
    x->parent = y;
    y->left_child = x;
}

void RBTree::right_rotate(RBNode *x){
    RBNode *y = x->left_child;
    x->left_child = y->right_child;
    if(y->right_child != nil)
        y->right_child->parent = x;
    y->parent = x->parent;
    if(x->parent == nil)
        root = y;
    else if(x->parent->left_child == x)
        x->parent->left_child = y;
    else
        x->parent->right_child = y;
    x->parent = y;
    y->right_child = x;
}

RBNode* RBTree::insert_bst(RBNode *base_parent, RBNode *base, Worker data){
    string key = data.get_fullname();
    if(base == nil){ // либо пустое дерево, либо точка останова рекурсии        
        base = new RBNode(data, Color::RED, nil, nil, base_parent);
        if(base_parent == nil)
            root = base;
        else{
	        if(key > base_parent->key)
	            base_parent->right_child = base;
	        else
	            base_parent->left_child = base;
        }
    }
    else{                
        if(key <= base->key)
            return insert_bst(base, base->left_child, data);
        else
            return insert_bst(base, base->right_child, data);
    }
    return base;
}

void RBTree::insert(Worker data){
	RBNode *z = insert_bst(nil, root, data);
	while(z->parent->color == Color::RED){
        // case A
        if(z->parent->parent->left_child == z->parent){
            if(z->parent->parent->right_child->color == Color::RED){ // A.1
                z->parent->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                z->parent->parent->right_child->color = Color::BLACK;
                z = z->parent->parent;
            }
            else{
                if(z->parent->right_child == z){ // A.2
                    z = z->parent;
                    left_rotate(z);
                }
                // A.3
                z->parent->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                right_rotate(z->parent->parent);
            }
        }
        
        // case B (симметрично A)
        else{
            if(z->parent->parent->left_child->color == Color::RED){ // B.1
                z->parent->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                z->parent->parent->left_child->color = Color::BLACK;
                z = z->parent->parent;
            }
            else{
                if(z->parent->left_child == z){ // B.2
                    z = z->parent;
                    right_rotate(z);
                }
                // B.3
                z->parent->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                left_rotate(z->parent->parent);
                
            }
        }
    }
	root->color = Color::BLACK; // на всякий
}

bool RBTree::find(const string &key){
	RBNode *cur_node = root;
	while (cur_node != nil && cur_node->key != key){
	    if (cur_node->key > key)
	        cur_node = cur_node->left_child;
	    else
	        cur_node = cur_node->right_child;
	}
	return cur_node != nil;
}
