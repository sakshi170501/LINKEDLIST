class Solution {
public:

    Node* reversal(Node* &head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    Node* addOne(Node* head) {

        // Reverse the linked list
        head = reversal(head);

        int carry = 1;
        Node* temp = head;

        while (temp != NULL) {

            int sum = temp->data + carry;

            temp->data = sum % 10;
            carry = sum / 10;

            // If this is the last node and carry remains
            if (temp->next == NULL && carry != 0) {
                Node* newNode = new Node(carry);
                temp->next = newNode;
                carry = 0;
                break;
            }

            temp = temp->next;
        }

        // Reverse back
        head = reversal(head);

        return head;
    }
};