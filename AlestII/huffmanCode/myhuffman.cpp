#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define TAM 256
using namespace std;

struct Node
{
    unsigned char c;
    int frequencia;
    Node *esq;
    Node *dir;
    Node() : c('\0'), frequencia(0), esq(nullptr), dir(nullptr) {};
    Node(unsigned char c, int frequencia) : c(c), frequencia(frequencia) {};
};

struct comp
{
    bool operator()(Node *l, Node *r)
    {

        return l->frequencia > r->frequencia;
    }
};

class HuffmanTree
{

private:
    Node *root; // raiz para a huffman tree
    priority_queue<Node *, vector<Node *>, comp> minHeap;
    unordered_map<unsigned char, string> huffcode;
    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        deleteTree(node->esq);
        deleteTree(node->dir);
        delete node;
    }

public:
    ~HuffmanTree()
    {
        deleteTree(root);
    }

    void encode(Node *node, string str, unordered_map<unsigned char, string> &codificado)
    {
        if (node == nullptr)
            return;

        if (node->esq == nullptr && node->dir == nullptr)
        {
            codificado[node->c] = str;
        }

        encode(node->esq, str + "0", codificado);
        encode(node->dir, str + "1", codificado);
    }

    void decode(Node *node, string str, int &index)
    {
        if (node == nullptr)
            return;

        if (node->esq == nullptr && node->dir == nullptr)
        {
            cout << node->c;
            return;
        }

        index++;
        if (index >= (int)str.size())
            return;

        if (str[index] == '0')
            decode(node->esq, str, index);
        else
            decode(node->dir, str, index);
    }

    unordered_map<unsigned char, int> tabelaFrequencias(const string &texto)
    {
        unordered_map<unsigned char, int> frequencias;

        for (char c : texto)
        {
            frequencias[c]++;
        }

        return frequencias;
    }

    void criarMinHeap(const unordered_map<unsigned char, int> &frequencias)
    {
        for (const auto &par : frequencias)
        {
            minHeap.push(new Node(par.first, par.second));
        }

        cout << "\nNós na min-heap (em ordem crescente de frequência):" << endl;
        priority_queue<Node *, vector<Node *>, comp> tempHeap = minHeap; // copia minheap
        while (!tempHeap.empty())
        {
            Node *no = tempHeap.top();
            tempHeap.pop();
            cout << "Caractere: " << no->c << ", Frequência: " << no->frequencia << endl;
        }
        while (minHeap.size() != 1)
        {
            Node *left = minHeap.top();
            minHeap.pop();
            Node *right = minHeap.top();
            minHeap.pop();
            int soma = left->frequencia + right->frequencia;

            minHeap.push(getNode('\0', soma, left, right));
        }
        root = minHeap.top();
    }

    Node *getNode(unsigned char ch, int freq, Node *left, Node *right)
    {
        Node *node = new Node();

        node->c = ch;
        node->frequencia = freq;
        node->esq = left;
        node->dir = right;

        return node;
    }

    void huffmanPrinter(string texto)
    {

        unordered_map<unsigned char, int> frequencias = this->tabelaFrequencias(texto);
        this->criarMinHeap(frequencias);
        encode(root, "", huffcode);
        cout << "\nCODIFICADO =\n"
             << '\n';
        for (auto pair : huffcode)
        {
            cout << pair.first << " " << pair.second << '\n';
        }
        string str = "";
        for (auto ch : texto)
        {
            str += huffcode[ch];
        }
        cout << endl;
        cout << "\nDECODIFICADO:\n";
        int index = -1;
        while (index < (int)str.size() - 1)
        {
            decode(root, str, index);
        }
        cout << endl;
    }
};

int main()
{
    string texto = "teste muito bom";

    // cria a huffmantree
    HuffmanTree huffmanTree;

    huffmanTree.huffmanPrinter(texto);

    return 0;
}