/**
 题目描述
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 Return a deep copy of the list.
 
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *pNode = NULL;
        RandomListNode *pHead = NULL;
        RandomListNode *p     = NULL;
        
        p = head;
        while(p){
            if(!(pNode = (RandomListNode *)malloc(sizeof(RandomListNode)))){
                return NULL;
            }
            pNode->label  = p->label;
            pNode->next   = p->next;
            p->next       = pNode;
            p             = p->next->next;
        }
        
        p = head;
        while(p){
            p->next->random = (!p->random)? NULL:p->random->next;
            p = p->next->next;
        }
        
        /*恢复原始链表和拆出拷贝链表*/
        if(head){
            pHead = head->next;
            p = head;
            while(p->next->next){
                pNode = p->next->next;
                p->next->next = pNode->next;
                p->next = pNode;
                p = p->next;
            }
            p->next = NULL;
        }
        return pHead;
    }
};