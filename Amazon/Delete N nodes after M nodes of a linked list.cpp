class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* node = head;
        while(node!=nullptr)
        {
            Node* prev = nullptr;
            // Skip m nodes
            for(int i=0; i<m && node!=nullptr; i++){
                prev = node;
                node = node->next;
            }
            
            // Delete n nodes
            for(int i=0; i<n && node!=nullptr; i++)
            {
                Node* temp = node;
                node = node->next;
                delete temp;
            }
            prev->next = node;
        }
        return head;
    }
};