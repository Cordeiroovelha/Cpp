struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(0);
        ListNode* tail = newHead;
        int total{0}, carry{0};

        while (l1 || l2 || carry) { // enquanto tiver lista
            total = carry; // vai somando com o carry do nó anterior

            if(l1){ // adiciona o valor da l1 na var total e avança para o proximo nó
            total += l1->val;
            l1 = l1->next;
            }
            if(l2){
                total += l2->val;
                l2 = l2->next;
            }
            
            int num = total % 10; // verifica se tem resto
            carry = total / 10;
            newHead->next = new ListNode(num); // adiciona o resto no proximo nó
            newHead = newHead->next;
        }       
        
        ListNode* Resulte = tail->next;
        delete tail;
        return Resulte;

    }
};