#include "rbtree.h"

#include <stdlib.h>


// 트리 첫 생성
rbtree *new_rbtree(void) {
  // TODO: initialize struct if needed
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  node_t *nilNode = (node_t *)calloc(1,sizeof(node_t)); //nil노드 하나 만듬
  nilNode->color = RBTREE_BLACK;
  p -> nil  = nilNode; // 트리 p의 nil이  nil노드를 가리킨다.
  p -> root = nilNode;// 트리 p의 root이 nil노드를 가리킨다.
  
  return p;
}

void delete_node(rbtree *t,node_t* n){
  if(n != t->nil)
  {
  delete_node(t, n->left);
  delete_node(t, n->right);
  free(n);
  }
}  

// tree 전체 노드를 free
void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  if(t->root)
    delete_node(t, t->root);
  free(t->nil);
  free(t);
}

void rotate_left(rbtree *t,node_t *x){
  node_t *y = x->right; //자리 변환하기 위해 y 임시 저장.
  
  x->right = y->left; //y의 왼쪽 서브트리를 x의 오른쪽 서브트리로 옮긴다.
  if(y->left != t->nil){
    y->left->parent = x;
  }
  y->parent = x->parent; //x의 부모를 y로 연결
  if(x->parent == t->nil){
    t->root = y;  
  }
  else if(x == x->parent->left){
    x->parent->left = y;
  }
  else{
    x->parent->right = y;
  }
  y->left =x; //x를 y의 왼쪽으로 놓는다.
  x->parent = y;  
}

void rotate_right(rbtree *t,node_t *x){
  node_t *y = x->left; //자리 변환하기 위해 y 임시 저장.
  
  x->left = y->right; //y의 왼쪽 서브트리를 x의 오른쪽 서브트리로 옮긴다.
  if(y->right != t->nil){
    y->right->parent = x;
  }
  y->parent = x->parent; //x의 부모를 y로 연결
  if(x->parent == t->nil){
    t->root = y;  
  }
  else if(x == x->parent->right){
    x->parent->right = y;
  }
  else{
    x->parent->left = y;
  }
  y->right =x; //x를 y의 왼쪽으로 놓는다.
  x->parent = y;  
}
void rbtree_insert_fixup(rbtree *t, node_t *z){
node_t* y;
  while (z->parent->color == RBTREE_RED){ //부모주소가 존재하고 부모색깔이 빨간색일 경우, 부모가 적색일때만 루프 수행
    //new node의 부모노드가 조부모의 왼쪽 자식인 경우라고 가정한다. 경우 고려 6가지가 대칭이기때문에 3가지 경우만 고려하면 된다.
    if(z->parent == z->parent->parent->left){
      // 부모노드의 형제 노드 정의, 
      y = z->parent->parent->right; //자료형이 맞다. 확인 해보자. 삼촌의 색깔에 따라 경우가 3가지 나뉜다.
      //case1(uncle's color is RED)
      if (y->color == RBTREE_RED){ // 경우 1 실행
        z->parent->color = RBTREE_BLACK; //부모 노드 색깔 검정으로 바꾼다.
        y->color = RBTREE_BLACK; //삼촌 노드 색깔 빨강 에서 검정으로 바꿈.
        z->parent->parent->color = RBTREE_RED; // 조부모 노드 색깔 빨간색으로 바꾼다. 이유는 위키피디아 세번째경우에 해당한다.
        z = z->parent->parent; // 유일한 재귀 호출. 조부모 노드가 2번 속성이나 4번 속성 만족하지 않을 수 있어서. 재귀 호출은 회전 작업하기전에 적용해야 한다.
      }
      else{
        if( z == z->parent->right){
          z = z->parent;
          rotate_left(t,z);
          }
        // case 3 : z의 삼촌 y가 흑색이며 z가 오른쪽 자식인 경우
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        rotate_right(t, z->parent->parent);
       }      
    }
    else{ //new node의 부모 노드가 오른쪽 자식인 경우
      // 부모노드의 형제 노드 정의, 
      y = z->parent->parent->left; //자료형이 맞다. 확인 해보자. 삼촌의 색깔에 따라 경우가 3가지 나뉜다.
      if (y->color == RBTREE_RED){ // 경우 1 실행
        z->parent->color = RBTREE_BLACK; //부모 노드 색깔 검정으로 바꾼다.
        y->color = RBTREE_BLACK; //삼촌 노드 색깔 빨강 에서 검정으로 바꿈.
        z->parent->parent->color = RBTREE_RED; // 조부모 노드 색깔 빨간색으로 바꾼다. 이유는 위키피디아 세번째경우에 해당한다.
        z = z->parent->parent; // 유일한 재귀 호출. 조부모 노드가 2번 속성이나 4번 속성 만족하지 않을 수 있어서. 재귀 호출은 회전 작업하기전에 적용해야 한다.
      }
      else 
      {
        if( z == z->parent->left){
          z = z->parent;
          rotate_right(t,z);
        }
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        rotate_left(t, z->parent->parent);
      }
    }
  }  
  t->root->color = RBTREE_BLACK;
}


// key 값을 가지고 tree에 insert
node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *y = t->nil;
  node_t *x = t->root;
  node_t *z = (node_t *)calloc(1, sizeof(node_t));
  z->key = key;
  
  while (x != t->nil){
    y = x;
    if(z->key < x->key)
      x= x->left;         
    else
      x= x->right;    
  }
  z->parent = y;
  if (y == t->nil){
    t->root = z;
  }
  else if(z->key < y->key){
    y->left = z;
  }
  else{
    y->right = z;
  }
  z->left = t->nil;
  z->right = t->nil;
  z->color = RBTREE_RED;
  rbtree_insert_fixup(t,z);
  return t->root;
}
void rb_transplant(rbtree *t, node_t *u, node_t* v){
  if(u->parent == t->nil)
    t->root = v;
  else if(u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;

  v->parent = u->parent;    
}
  
node_t *rbtree_find(const rbtree *t, const key_t k) {
  // TODO: implement find
  node_t *x = t->root;
  while (x != NULL && k != x->key){
    if (k < x->key){
        x = x->left;
    }
    else x = x->right;    
    }
    return x;
  }

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  node_t *x = t->root;
  while(x->left != t->nil)
    x= x->left;
  return x;
}

node_t *node_min(const rbtree *t, node_t *n){

  while(n->left != t->nil)
    n = n->left;
  return n;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  node_t *x = t->root;
  while(x->right != t->nil)
    x = x->right;
  return x;
}

void rb_delete_fixup(rbtree *t,node_t *x){
  while(x != t->root && x->color == RBTREE_BLACK)
  { 
    node_t *w;
    if( x == x->parent->left)
    {
      w = x->parent->right;
      if( w->color == RBTREE_RED)
      {
        w->color = RBTREE_BLACK;
        x->parent->color = RBTREE_RED;
        rotate_left(t,x->parent);
        w = x->parent->right;
      }
      if(w->left->color == RBTREE_BLACK && w->right->color == RBTREE_BLACK)
      {
        w->color = RBTREE_RED;
        x = x->parent;
      }
      else
      {
        if(w->right->color == RBTREE_BLACK)
        {
          w->left->color = RBTREE_BLACK;
          w->color = RBTREE_RED;
          rotate_right(t,w);
          w = x->parent->right;
        }
        w->color = x->parent->color;
        x->parent->color = RBTREE_BLACK;
        w->right->color = RBTREE_BLACK;
        rotate_left(t,x->parent);
        x = t->root;
      }
    }
    else  // x == x.p.right일때
    {
      w = x->parent->left;
      if( w->color == RBTREE_RED)
      {
        w->color = RBTREE_BLACK;
        x->parent->color = RBTREE_RED;
        rotate_right(t,x->parent);
        w = x->parent->left;
      }
      if(w->right->color == RBTREE_BLACK && w->left->color == RBTREE_BLACK)
      {
        w->color = RBTREE_RED;
        x = x->parent;
      }
      else
      {
        if(w->left->color == RBTREE_BLACK)
        {
          w->right->color = RBTREE_BLACK;
          w->color = RBTREE_RED;
          rotate_left(t,w);
          w = x->parent->left;
        }
        w->color = x->parent->color;
        x->parent->color = RBTREE_BLACK;
        w->left->color = RBTREE_BLACK;
        rotate_right(t,x->parent);
        x = t->root;
      }  
    }
  }
  x->color = RBTREE_BLACK;
}

int rbtree_erase(rbtree *t, node_t *z) 
{
  // TODO: implement erase
  node_t *x;
  node_t *y = z; // y는 노드에서 삭제된 노드 또는 트리에서 이동한 노드를 가리킨다.
  color_t y_origin_color = y->color;
  if(z->left == t->nil){
    x = z->right;
    rb_transplant(t, z, z->right);    
  }
  else if(z->right == t->nil){
    x = z->left;
    rb_transplant(t, z, z->left);
  }
  else{
    y = node_min(t,z->right);
    y_origin_color = y->color;
    x = y->right;
    if (y->parent == z)
      x->parent = y;
    else{
      rb_transplant(t, y, y->right);
      y->right = z->right;
      y->right->parent = y;      
    }
    rb_transplant(t, z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }
  if(y_origin_color == RBTREE_BLACK)
    rb_delete_fixup(t,x);
  //지우는 노드 데이터 할당 된것도 free해주어야 한다.
  free(z);
  return 0;  
}
void inorder_rbtree_walk(const rbtree *t, node_t *x, key_t *arr,  size_t *pcnt, const size_t n){
  if(x == t->nil){
    return;
  }
    inorder_rbtree_walk(t,x->left,arr,pcnt,n);
    if(*pcnt < n){
      arr[(*pcnt)++] = x->key;
    }
    else{
      return;
    }
    inorder_rbtree_walk(t,x->right,arr,pcnt,n);
  }



int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array , 트리 들어갔다와서 중위순회한 값을 arr에 담아라.
  if(t->root == t->nil){
    return 0;
  }
  else{
    size_t cnt = 0;
    inorder_rbtree_walk(t, t->root, arr, &cnt, n);
  }
 
  return 0;
}
