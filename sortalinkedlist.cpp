class Solution {
public:

    void insertAttail(Node* toInsert, Node* &head, Node* &tail) {

        if (head == NULL && tail == NULL) {
            head = toInsert;
            tail = toInsert;
        }
        else {
            tail->next = toInsert;
            tail = toInsert;
        }
    }

    Node* segregate(Node* head) {

        Node* zerohead = NULL;
        Node* zerotail = NULL;

        Node* onehead = NULL;
        Node* onetail = NULL;

        Node* twohead = NULL;
        Node* twotail = NULL;

        Node* temp = head;

        while (temp != NULL) {

            Node* toInsert = temp;
            temp = temp->next;

            toInsert->next = NULL;

            if (toInsert->data == 0) {
                insertAttail(toInsert, zerohead, zerotail);
            }
            else if (toInsert->data == 1) {
                insertAttail(toInsert, onehead, onetail);
            }
            else if (toInsert->data == 2) {
                insertAttail(toInsert, twohead, twotail);
            }
        }

        // Connect 0-list, 1-list and 2-list

        if (zerohead != NULL) {

            if (onehead != NULL) {
                zerotail->next = onehead;

                if (twohead != NULL) {
                    onetail->next = twohead;
                }

                return zerohead;
            }
            else {
                zerotail->next = twohead;
                return zerohead;
            }
        }
        else {

            if (onehead != NULL) {

                if (twohead != NULL) {
                    onetail->next = twohead;
                }

                return onehead;
            }
            else {
                return twohead;
            }
        }
    }
};