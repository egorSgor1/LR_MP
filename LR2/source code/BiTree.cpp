/*!
\file
\brief Файл реализаций методов класса BiTree
*/

#include "BiTree.h"

void BiTree::del(BiNode *node){
    if (node){
        del(node->left_child);
        del(node->right_child);
        delete node;
    }
}

bool BiTree::find(const string &key){
    BiNode *cur_node = root;
    while (cur_node && cur_node->key != key){
        if (cur_node->key > key)
            cur_node = cur_node->left_child;
        else
            cur_node = cur_node->right_child;
    }
    return cur_node != NULL;
}

void BiTree::insert(Worker data){
    if (root==NULL){
    	root = new BiNode(data);
    	return;
    }
    
    string key = data.get_fullname();
    BiNode *cur_node = root;
    while (true){ 
        if (cur_node->key >= key){
        	if (cur_node->left_child == NULL){
            	cur_node->left_child = new BiNode(data);
            	break;            
        	}
        	cur_node = cur_node->left_child;
        }
         
        else{
        	if (cur_node->right_child == NULL){
            	cur_node->right_child = new BiNode(data);
            	break;
        	}
        	cur_node = cur_node->right_child;
        }
    }
}
