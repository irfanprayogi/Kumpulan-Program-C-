// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Operasi Binary Tree

#include <iostream>
#include <iomanip>

using namespace std;

struct TreeNode
{
    char value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

int main()
{
    int pilih;

    TreeNode *root = new TreeNode('M');
    root->left = new TreeNode('E');
    root->right = new TreeNode('L');
    root->left->left = new TreeNode('A');
    root->left->right = new TreeNode('I');
    root->left->left->right = new TreeNode('U');
    root->right->left = new TreeNode('B');
    root->right->right = new TreeNode('O');
    root->right->right->left = new TreeNode('D');

    do
    {
        cout << "======================================" << endl;
        cout << setw(35) << "+++Menu Operation Binary Tree+++" << endl;
        cout << "======================================" << endl;
        cout << setw(15) << "1. PreOrder\t";
        cout << setw(15) << "3. PostOrder" << endl;
        cout << setw(14) << "2. InOrder\t";
        cout << setw(18) << "4. Exit Operasi" << endl;
        cout << "======================================" << endl;
        cout << "Masukkan Pilihan Operasi: ";
        cin >> pilih;

        if (pilih == 1)
        {
            cout << "======================================" << endl;
            cout << "Gambar Binary Tree" << endl;
            cout << setw(10) << "M" << endl;
            cout << setw(10) << "/\t\t"
                                "\\"
                 << endl;
            cout << setw(5) << "E" << setw(10) << "L" << endl;
            cout << setw(4) << "/\t" << setw(3) << "\\" << setw(7) << "/\t" << setw(1) << "\\" << endl;
            cout << setw(2) << "A" << setw(6) << "I" << setw(4) << "B" << setw(6) << "O" << endl;
            cout << setw(3) << "\\" << setw(14) << "/" << endl;
            cout << setw(4) << "U" << setw(12) << "D" << endl
                 << endl;

            cout << "Hasil Preorder: ";
            preorder(root);
        }
        else if (pilih == 2)
        {
            cout << "======================================" << endl;
            cout << "Gambar Binary Tree" << endl;
            cout << setw(10) << "M" << endl;
            cout << setw(10) << "/\t\t"
                                "\\"
                 << endl;
            cout << setw(5) << "E" << setw(10) << "L" << endl;
            cout << setw(4) << "/\t" << setw(3) << "\\" << setw(7) << "/\t" << setw(1) << "\\" << endl;
            cout << setw(2) << "A" << setw(6) << "I" << setw(4) << "B" << setw(6) << "O" << endl;
            cout << setw(3) << "\\" << setw(14) << "/" << endl;
            cout << setw(4) << "U" << setw(12) << "D" << endl
                 << endl;

            cout << "Hasil Inorder: ";
            inorder(root);
        }
        else if (pilih == 3)
        {
            cout << "======================================" << endl;
            cout << "Gambar Binary Tree" << endl;
            cout << setw(10) << "M" << endl;
            cout << setw(10) << "/\t\t"
                                "\\"
                 << endl;
            cout << setw(5) << "E" << setw(10) << "L" << endl;
            cout << setw(4) << "/\t" << setw(3) << "\\" << setw(7) << "/\t" << setw(1) << "\\" << endl;
            cout << setw(2) << "A" << setw(6) << "I" << setw(4) << "B" << setw(6) << "O" << endl;
            cout << setw(3) << "\\" << setw(14) << "/" << endl;
            cout << setw(4) << "U" << setw(12) << "D" << endl
                 << endl;

            cout << "Hasil Postorder: ";
            postorder(root);
        }
        else if (pilih == 4)
        {
            cout << "Exit Operation...";
        }
        else
        {
            cout << "Maaf Pilihan Anda Belum Tersedia";
        }
        cout << endl
             << endl;
    } while (pilih != 4);

    return 0;
}