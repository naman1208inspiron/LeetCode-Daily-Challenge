/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
state  |  status                                |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-1     |  if camera is needed                   |
0      |  if the node has a camera              |
1      |  if the node is covered by a camera    |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

==> we would love to put the camera on the parent of the leaf node, as it would cover the node, the leaf node(s) and the parent of that node.
*/
class Solution {    
    int cam=0;
public:
    int minCameraCover(TreeNode* root) {
        if(findCam(root)== -1) cam++;
        return cam;
    }
    int findCam(TreeNode* root){
        if(root== NULL) return 1;
        
        int left= findCam(root->left);
        int right= findCam(root->right);
        
        // if cam is needed by any of my child, i need to have a camera
        if(left== -1 || right== -1){
            cam++;
            return 0;
        }
        
        // if any of my child has a camera, then i am also covered
        else if(left== 0 || right== 0){
            return 1;
        }
        
        // last case--> my children are covered, I need my parent to add a camera
        return -1;
    }
};
