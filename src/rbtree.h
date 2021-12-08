#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <stddef.h>

typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;

typedef int key_t;

typedef struct node_t {
  color_t color; 
  key_t key;
  struct node_t *parent, *left, *right; //node_t 자기 참조 구조체 parent, left,right 포인터 변수 만듬
} node_t;

typedef struct {
  node_t *root; //node_t 구조체를 가리키는 root라는 포인터 변수 생성
  node_t *nil;  // for sentinel 한계 조건을 다루기 편리하도록 nil을 표현하기 위해 하나의 경계 노드(sentinel)을 사용한다
} rbtree;

rbtree *new_rbtree(void);
void delete_rbtree(rbtree *);

node_t *rbtree_insert(rbtree *, const key_t);
node_t *rbtree_find(const rbtree *, const key_t);
node_t *rbtree_min(const rbtree *);
node_t *rbtree_max(const rbtree *);
int rbtree_erase(rbtree *, node_t *);

int rbtree_to_array(const rbtree *, key_t *, const size_t);

#endif  // _RBTREE_H_
