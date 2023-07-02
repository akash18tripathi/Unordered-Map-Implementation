#include <iostream>
#include <sstream> 

#define bucket_size 100003

using namespace std;

// =============================== ** Unordered Map Class ** =======================================
template<class A,class B> 
class Unordered_Map{

    // Node class for LinkedList
    public:
    class Node{
        public:

        A key;
        B val;
        Node* right;

        Node(){

        }
        
        Node(A k,B v){
            this->key=k;
            this->val=v;
            this->right=NULL;
        }
    };

    Node** arr;

    Unordered_Map(){
        arr = new Node*[bucket_size];
    }

    // hash function for integer
    int hashF(int key){
        return key%bucket_size;
    }

    // hash function for float
    int hashF(float key){
        int temp = (int) key;
        return temp%bucket_size;
    }

    // hash function for double
    int hashF(double key){
        int temp = (int) key;
        return temp%bucket_size;
    }

    // hash function for char
    int hashF(char key){
        int temp = (int) key;
        return temp%bucket_size;
    }

    // hash function for string
    int hashF(string key){

        string input = key;
        int hashVal=0;
        int tempVar=1;
        for(int i=0;i<input.length();i++){
            int asci = int(input[i]);
            hashVal = (hashVal+ (asci*tempVar)%bucket_size)%bucket_size;
            tempVar = (tempVar*13)%bucket_size;
        }
        return hashVal%bucket_size;
    }

    // Inserting 'v' in key 'k' in unordered_map
    void insert(A k,B v){
        int hashVal = this->hashF(k);
        if(arr[hashVal]==NULL){
            Node* n =new Node(k,v);
            arr[hashVal]=n;
        }else{
            Node* temp = arr[hashVal];
            while(temp->right!=NULL){
                if(temp->key==k){
                    temp->val=v;
                    return;
                }
                temp = temp->right;
            }
            if(temp->key==k){
                temp->val=v;
                return;
            }
            Node* n = new Node(k,v);
            temp->right=n;
        }
    }

    // Remove key from unordered_map
    void erase(A k){
        int hashVal = this->hashF(k);
        if(arr[hashVal]==NULL){
            return;
        }
        if(arr[hashVal]->key==k){
            arr[hashVal] = arr[hashVal]->right;
            return;
        }
        Node* temp = arr[hashVal];
        while(temp->right!=NULL && temp->right->key!=k){
            temp=temp->right;
        }
        if(temp->right==NULL){
            return;
        }
        Node* n = temp->right;
        temp->right = n->right;
        n->right=NULL;
        free(n);
    }

    // check if key exists or not
    bool find(A k){
        int hashVal = this->hashF(k);
        if(arr[hashVal]==NULL){
            return false;
        }
        Node* temp = arr[hashVal];
        while(temp!=NULL){
            if(temp->key==k){
                return true;
            }
            temp=temp->right;
        }
        return false;
        
    }

    // Get the value corresponding to a particular key.
    B operator[](A k){
        int hashVal=this->hashF(k);
        Node* p = arr[hashVal];
        while(p!=NULL){
            if(p->key==k) return p->val;
            p=p->right;  
        }
        B df = B();
        return df;
    }


};



// =============================== ** Driver Code implements Question ** =======================================

int main(){
    
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    Unordered_Map<int,int> mp;
    int distinctElements=0;

    for(int i=0;i<k;i++){
        if(mp.find(arr[i])){
            mp.insert(arr[i],mp[arr[i]]+1);
        }else{
            distinctElements++;
            mp.insert(arr[i],1);
        }
    }
    int ans[n-k+1];
    int window=0;
    ans[window]=distinctElements;
    int i=1,j=k;
    while(j<n){
        window++;
        mp.insert(arr[i-1],mp[arr[i-1]]-1);
        if(mp[arr[i-1]]==0){
            distinctElements--;
            mp.erase(arr[i-1]);
        }
        if(mp.find(arr[j])){
            mp.insert(arr[j],mp[arr[j]]+1);
        }else{
            mp.insert(arr[j],1);
            distinctElements++;
        }
        ans[window]=distinctElements;
        i++;
        j++;
    }

    for(int i=0;i<n-k+1;i++){
        cout << ans[i] << " ";
    }

    return 0;
}