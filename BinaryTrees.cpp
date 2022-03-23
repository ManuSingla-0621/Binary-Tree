#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
int HeightOfTree(Node* root)
{
    if(root==NULL)
    return 0;
    int lh=HeightOfTree(root->left);
    int rh=HeightOfTree(root->right);
    return max(lh,rh)+1;
}
bool SameTree(Node* r,Node* p)
{
if(r==NULL && p==NULL)
return true;
else if(r!=NULL && p==NULL)
return false;
else if(p!=NULL && r==NULL)
return false;

bool left=SameTree(r->left,p->left);
bool right=SameTree(r->right,p->right);
bool value=r->data==p->data;

if(left && right && value)
return true;
else
return false;
}
bool MirrorTree(Node* r,Node* p)
{
if(r==NULL && p==NULL)
return true;
else if(r!=NULL && p==NULL)
return false;
else if(p!=NULL && r==NULL)
return false;

bool left=SameTree(r->left,p->right);
bool right=SameTree(r->right,p->left);
bool value=r->data==p->data;

if(left && right && value)
return true;
else
return false;
}
int BalancedTree(Node* root)
{
    if(root==0)
    return 0;
    int lh=HeightOfTree(root->left);
    if(lh==-1)
    return -1;
    int rh=HeightOfTree(root->right);
    if(rh==-1)
    return -1;
    if(abs(lh-rh)>1)
    return -1;
    return max(lh,rh)+1;
}
void RightView(Node* root,int level,vector<int> &ans)
{
if(root==NULL)
return ;
if(level==ans.size())
{
ans.push_back(root->data);
}
RightView(root->right,level+1,ans);
RightView(root->left,level+1,ans);
}
void LeftView(Node* root,int level,vector<int> &ans)
{
if(root==NULL)
return ;
if(level==ans.size())
{
ans.push_back(root->data);
}
LeftView(root->left,level+1,ans);
LeftView(root->right,level+1,ans);
}
void BottomView(Node* root,vector<int> &ans)
{
if(root==NULL)
return;
map<int,int>mpp;
queue<pair<Node*,int>>q;
q.push({root,0});
while(!q.empty())
{
    auto p=q.front();
    Node* node=p.first;
    int level=p.second;
    q.pop();
    mpp[level]=node->data;
    if(node->left)
     q.push({node->left,level-1});
    if(node->right)
     q.push({node->right,level+1});
}
for(auto it:mpp)
ans.push_back(it.second);
}
void TopView(Node* root,vector<int> &ans)
{
if(root==NULL)
return;
map<int,int>mpp;
queue<pair<Node*,int>>q;
q.push({root,0});
while(!q.empty())
{
    auto p=q.front();
    Node* node=p.first;
    int level=p.second;
    q.pop();
    if(mpp.find(level)==mpp.end())
    mpp[level]=node->data;
    if(node->left)
     q.push({node->left,level-1});
    if(node->right)
     q.push({node->right,level+1});
}
for(auto it:mpp)
ans.push_back(it.second);
}
void PreOrder(Node* root,vector<int> &ans)
{
    if(root==NULL)
    return;
    ans.push_back(root->data);
    PreOrder(root->left,ans);
    PreOrder(root->right,ans);
}
void PostOrder(Node* root,vector<int> &ans)
{
    if(root==NULL)
    return;
    PreOrder(root->left,ans);
    PreOrder(root->right,ans);
    ans.push_back(root->data);
}
void InOrder(Node* root,vector<int> &ans)
{
    if(root==NULL)
    return;
    PreOrder(root->left,ans);
    ans.push_back(root->data);
    PreOrder(root->right,ans);
}
void ReverseLevelOrderTraversal(Node* root,vector<int> &ans)
{
 if(root==NULL)
  return;
 else{
 queue<Node*>q;
 q.push(root);
 while(!q.empty())
 {
     Node* p=q.front();
     q.pop();
     ans.push_back(p->data);
     if(p->right)
     q.push(p->right);
     if(p->left)
     q.push(p->left);
 }
 reverse(ans.begin(),ans.end());
 }
}
void LevelOrderTraversal(Node* root,vector<int> &ans)
{
 if(root==NULL)
  return;
 else{
 queue<Node*>q;
 q.push(root);
 while(!q.empty())
 {
     Node* p=q.front();
     q.pop();
     ans.push_back(p->data);
     if(p->left)
     q.push(p->left);
     if(p->right)
     q.push(p->right);
 }
 }
}
int main()
{
    vector<int>ans;
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    Node* root2=new Node(1);
    root2->left=new Node(3);
    root2->right=new Node(2);
    root2->left->left=new Node(6);
    root2->left->right=new Node(7);
    root2->right->left=new Node(4);
    root2->right->right=new Node(10);
    // int ans=BalancedTree(root);
    // cout<<ans<<endl;
    // ReverseLevelOrderTraversal(root,ans);
    // for(auto it:ans)
    // cout<<it<<" ";
    TopView(root,ans);
    for(auto it:ans)
    cout<<it<<" ";
    return 0;
}