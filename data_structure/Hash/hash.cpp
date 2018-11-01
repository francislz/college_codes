#include <iostream>
using namespace std;

const int PRIME = 37;

int hashFunction(string s, int M){
    long h = 0;
    for(unsigned int i = 0; i < s.length(); ++i){
        h = (PRIME * h + s[i]) % M;
    }
    return h;
}

class Node{
    friend class Hash;
    private:
        string key;
        string value;
        Node* next = NULL;
    public:
        Node(){
            key = "";
            value = "";
        }
};

class Hash{
    private:
        Node** elements;
        int capacity;
    public:
        Hash(int cap = 100){
            elements = new Node*[cap];
            capacity = cap;
            for(int i = 0; i < capacity; ++i)
                elements[i] = NULL;
        }
        ~Hash(){
            for(int i = 0; i < capacity; i++){
                Node* temp = elements[i];
                while(temp != NULL){
                    Node* aux = temp;
                    temp = temp->next;
                    delete aux;
                }
            }
            delete[] elements;
        }
        string recover(string k){
            int h = hashFunction(k, capacity);
            if((elements[h] != NULL) and (elements[h]->key == k)){
                return elements[h]->value;
            }
            else{
                Node* temp = elements[h];
                while((temp != NULL) and (temp->key != k)){
                    temp = temp->next;
                }
                
                if((temp != NULL) and (temp->key == k)){
                    return temp->value;
                }
                else{
                    return "NOT FOUND!";
                }
            }
        }
        
        void insert(string k, string v){
            int h = hashFunction(k, capacity);
            if(recover(k) == "NOT FOUND!"){
                if(elements[h] == NULL){
                    elements[h] = new Node;
                    elements[h]->key = k;
                    elements[h]->value = v;
                }
                else{
                    cout << "CRASHED" << endl;
                    Node* aux = elements[h];
                    while(aux->next != NULL){
                        aux = aux->next;
                    }
                    
                    Node* temp = new Node;
                    temp->key = k;
                    temp->value = v;
                    aux->next = temp;
                }
            }
            else{
                cout << "THIS ITEM IS ALREADY IN THE TABLE!" << endl;
            }
        }
        
        void changeValue(string k, string v){
            int h = hashFunction(k, capacity);
            if((elements[h] != NULL) and (elements[h]->key == k)){
                elements[h]->value = v;
            }
            else{
                Node* temp = elements[h];
                while((temp != NULL) and (temp->key != k)){
                    temp = temp->next;
                }
                if((temp != NULL) and (temp->key == k)){
                    temp->value = v;
                }
                else{
                    cout << "CHANGING ERROR!" << endl;
                }
            }
        }
        
        void removeElement(string k){
            int h = hashFunction(k, capacity);
            if((elements[h] != NULL) and (elements[h]->key == k)){
                Node* temp = elements[h];
                elements[h] = elements[h]->next;
                delete temp;
            }
            else{
                Node* temp = elements[h];
                Node* prev;
                while((temp != NULL) and (temp->key != k)){
                    prev = temp;
                    temp = temp->next;
                }
                if((temp != NULL) and (temp->key == k)){
                    prev->next = temp->next;
                    delete temp;
                }
                else{
                    cout << "ERROR TRYING TO REMOVE!" << endl;
                }
            }
        }
        
        void debug(){
            Node* temp;
            for(int i = 0; i < capacity; ++i){
                cout << i << ":";
                temp = elements[i];
                while(temp != NULL){
                    cout << "[" << temp->key << "/" << temp->value <<  "]->";
                    temp = temp->next;
                }
                cout << "NULL " << endl;
            }
        }
};

int main(){
    Hash table(10);
    table.insert("Dr", "e quem tem doutorado");
    table.insert("Jack", "Franciscone Luiz");
    table.insert("nome", "Isabel");
    table.insert("God", "Xina");
    table.insert("Fode", "Forte");
    table.insert("E ai", "Vamo fecha");
    
    table.debug();
    return 0;
}
