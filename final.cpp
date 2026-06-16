#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

/*================ PRODUCT ================*/
// This class acts like a template for creating a single item/product.
class Product {
public:
    int id;            // Unique number for the item
    string name;       // Name of the item
    double price;      // Cost of the item
    int popularity;    // Rating or popularity score

    // Constructor to easily create a product
    Product(int i = 0, string n = "", double p = 0, int pop = 0) {
        id = i;
        name = n;
        price = p;
        popularity = pop;
    }
};

/*================ BST TREE ================*/
// Node structure for a Binary Search Tree (BST)
class BSTNode {
public:
    Product data;       // Stores the product details
    BSTNode *left, *right; // Pointers to left and right child nodes

    BSTNode(Product p) {
        data = p;
        left = right = NULL;
    }
};

// Function to put a new product into the BST based on its ID
BSTNode* insertBST(BSTNode* root, Product p) {
    if (root == NULL)
        return new BSTNode(p); // If space is empty, make a new node here

    // Smaller IDs go left, larger IDs go right
    if (p.id < root->data.id)
        root->left = insertBST(root->left, p);
    else if (p.id > root->data.id)
        root->right = insertBST(root->right, p);

    return root;
}

// Function to print the BST items in sorted order (Left, Root, Right)
void inorderBST(BSTNode* root) {
    if (root == NULL)
        return;

    inorderBST(root->left); // Visit left side

    // Print current product data
    cout << "ID: " << root->data.id
         << " | " << root->data.name
         << " | Rs." << root->data.price
         << " | Popularity " << root->data.popularity << endl;

    inorderBST(root->right); // Visit right side
}

/*================ AVL TREE ================*/
// Node structure for an AVL Tree (A self-balancing BST)
class AVLNode {
public:
    Product data;
    AVLNode *left, *right;
    int height; // Keeps track of how tall this branch is

    AVLNode(Product p) {
        data = p;
        left = right = NULL;
        height = 1;
    }
};

// Helper function to safely get the height of a node
int heightAVL(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Check the balance status (Left height minus Right height)
int getBalance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return heightAVL(node->left) - heightAVL(node->right);
}

// Rotate nodes right to fix a left-heavy tree imbalance
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights after changing structure
    y->height = max(heightAVL(y->left), heightAVL(y->right)) + 1;
    x->height = max(heightAVL(x->left), heightAVL(x->right)) + 1;

    return x;
}

// Rotate nodes left to fix a right-heavy tree imbalance
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update heights after changing structure
    x->height = max(heightAVL(x->left), heightAVL(x->right)) + 1;
    y->height = max(heightAVL(y->left), heightAVL(y->right)) + 1;

    return y;
}

// Inserts a product and automatically balances the tree if it gets lopsided
AVLNode* insertAVL(AVLNode* root, Product p) {
    if (root == NULL)
        return new AVLNode(p);

    if (p.id < root->data.id)
        root->left = insertAVL(root->left, p);
    else if (p.id > root->data.id)
        root->right = insertAVL(root->right, p);
    else
        return root; // Duplicate IDs are not allowed

    // Update height of current node
    root->height = 1 + max(heightAVL(root->left), heightAVL(root->right));

    // Check balance factor to see if we need rotations
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && p.id < root->left->data.id)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && p.id > root->right->data.id)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && p.id > root->left->data.id) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && p.id < root->right->data.id) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print the AVL items in sorted order
void inorderAVL(AVLNode* root) {
    if (root == NULL)
        return;

    inorderAVL(root->left);

    cout << "ID: " << root->data.id
         << " | " << root->data.name
         << " | Rs." << root->data.price
         << " | Popularity " << root->data.popularity << endl;

    inorderAVL(root->right);
}

/*================ BINARY SEARCH ================*/
// Fast search method that works by dividing a sorted list in half repeatedly
int binarySearchByID(vector<Product>& products, int id) {
    int low = 0;
    int high = products.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2; // Find the middle index

        if (products[mid].id == id)
            return mid; // Found it! Return its location

        if (products[mid].id < id)
            low = mid + 1; // Look in the right half
        else
            high = mid - 1; // Look in the left half
    }

    return -1; // Return -1 if item doesn't exist
}

/*================ GRAPH ================*/
// Represents a network map (like delivery warehouses connected by roads)
class Graph {
public:
    int V; // Total number of locations (vertices)
    vector<vector<pair<int, int>>> adj; // Adjacency list: tracks connections and weights (distances)

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Connects location 'u' and location 'v' with a distance/cost of 'w'
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Two-way road
    }

    // Breadth-First Search: Explores the network level by level (closest locations first)
    void BFS(int start) {
        vector<bool> visited(V, false); // Keep track of where we have been
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (auto neighbour : adj[node]) {
                if (!visited[neighbour.first]) {
                    visited[neighbour.first] = true;
                    q.push(neighbour.first);
                }
            }
        }
        cout << endl;
    }

    // Helper function for DFS to recursively visit paths
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour.first])
                DFSUtil(neighbour.first, visited);
        }
    }

    // Depth-First Search: Explores the network by going as deep as possible down a path first
    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << endl;
    }

    // Dijkstra's Algorithm: Finds the absolute absolute shortest delivery route from a warehouse source
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX); // Set all initial distances to infinity

        // Min-priority queue to always process the closest reachable location first
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[src] = 0; // Distance to itself is zero
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                // If a shorter path to 'v' is found via 'u'
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest path results
        cout << "\nShortest Delivery Routes\n";
        for (int i = 0; i < V; i++) {
            cout << "Warehouse -> " << i << " = " << dist[i] << endl;
        }
    }
};

/*================ MAIN ================*/
int main() {
    // List of active products. 
    // ADDED 3 NEW ITEMS HERE: Keyboard (106), Mouse (107), Monitor (108)
    vector<Product> products = {
        {101, "Laptop", 75000, 95},
        {102, "Phone", 45000, 80},
        {103, "Headphones", 3000, 75},
        {104, "Smartwatch", 5000, 90},
        {105, "Camera", 35000, 70},
        {106, "Keyboard", 2500, 85},
        {107, "Mouse", 1500, 88},
        {108, "Monitor", 12000, 92}
    };

    BSTNode* bstRoot = NULL;
    AVLNode* avlRoot = NULL;

    // A Hash Map for instant product searches using their IDs
    unordered_map<int, Product> productMap;

    // Populate our BST, AVL, and Hash Map data structures with the product catalog
    for (auto p : products) {
        bstRoot = insertBST(bstRoot, p);
        avlRoot = insertAVL(avlRoot, p);
        productMap[p.id] = p;
    }

    // Make a copy of products and sort it by ID for the Binary Search mechanism
    vector<Product> sortedProducts = products;
    sort(sortedProducts.begin(), sortedProducts.end(), [](Product a, Product b) {
         return a.id < b.id;
    });

    // Queue to handle checkout orders in First-In, First-Out (FIFO) manner
    queue<int> orderQueue;
    
    // Stack to keep record of modifications so we can undo them in Last-In, First-Out (LIFO) manner
    stack<string> modifications;

    // Delivery network graph setup. Increased size to 8 to comfortably support added data nodes.
    Graph delivery(8);
    delivery.addEdge(0, 1, 10);
    delivery.addEdge(0, 2, 5);
    delivery.addEdge(1, 3, 2);
    delivery.addEdge(2, 3, 3);
    delivery.addEdge(3, 4, 1);
    delivery.addEdge(4, 5, 4); // Added a few more delivery links for the new catalog items
    delivery.addEdge(5, 6, 2);
    delivery.addEdge(6, 7, 3);

    int choice;

    // Main interaction loop
    do {
        cout << "\n====== SMART E-COMMERCE PLATFORM ======\n";
        cout << "1. Display Product Catalog (BST)\n";
        cout << "2. Display Product Catalog (AVL)\n";
        cout << "3. Show Recommended Products\n";
        cout << "4. Search Product By ID\n";
        cout << "5. Fast Product Lookup (Hashing)\n";
        cout << "6. Place Order\n";
        cout << "7. Process Next Order\n";
        cout << "8. Modify Order\n";
        cout << "9. Undo Last Modification\n";
        cout << "10. Delivery Network BFS\n";
        cout << "11. Delivery Network DFS\n";
        cout << "12. Shortest Delivery Route (Dijkstra)\n";
        cout << "13. View Cart (Pending Orders)\n";
        cout << "14. Remove Item from Cart\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "\nPRODUCT CATALOG (BST)\n";
            if(bstRoot) cout << "--- ROOT NODE IS: " << bstRoot->data.name << " ---\n";
            inorderBST(bstRoot);
            break;

        case 2:
            cout << "\nPRODUCT CATALOG (AVL)\n";
            if(avlRoot) cout << "--- ROOT NODE IS: " << avlRoot->data.name << " ---\n";
            inorderAVL(avlRoot);
            break;

        case 3: {
            // Sort items by popularity score descending to find recommendations
            vector<Product> temp = products;
            sort(temp.begin(), temp.end(), [](Product a, Product b) {
                     return a.popularity > b.popularity;
                 });

            cout << "\nTOP RECOMMENDATIONS\n";
            for (auto p : temp) {
                cout << p.name << " (Popularity " << p.popularity << ")\n";
            }
            break;
        }

        case 4: {
            int id;
            cout << "Enter Product ID: ";
            cin >> id;

            // Running binary search routine
            int idx = binarySearchByID(sortedProducts, id);
            if (idx != -1) {
                Product p = sortedProducts[idx];
                cout << "\nProduct Found\n";
                cout << "ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Price: Rs." << p.price << endl;
            } else {
                cout << "Product Not Found\n";
            }
            break;
        }

        case 5: {
            int id;
            cout << "Enter Product ID: ";
            cin >> id;

            // Instantly checks map array for existence of the ID key
            if (productMap.count(id)) {
                Product p = productMap[id];
                cout << "\nHash Lookup Successful\n";
                cout << p.name << " | Rs." << p.price << endl;
            } else {
                cout << "Product Not Found\n";
            }
            break;
        }

        case 6: {
            int id;
            cout << "Enter Product ID To Order: ";
            cin >> id;

            if (productMap.count(id)) {
                orderQueue.push(id); // Enqueue order ID
                cout << "Order Placed Successfully\n";
            } else {
                cout << "Invalid Product ID\n";
            }
            break;
        }

        case 7: {
            if (orderQueue.empty()) {
                cout << "No Orders Pending\n";
            } else {
                int id = orderQueue.front(); // Pull order from the front line
                orderQueue.pop();
                cout << "Processing Order : " << productMap[id].name << endl;
            }
            break;
        }

        case 8: {
            string action;
            cin.ignore();
            cout << "Enter Modification: ";
            getline(cin, action);

            modifications.push(action); // Save details to top of the stack
            cout << "Modification Saved\n";
            break;
        }

        case 9: {
            if (modifications.empty()) {
                cout << "Nothing To Undo\n";
            } else {
                cout << "Undo : " << modifications.top() << endl; // Pops last action off the stack
                modifications.pop();
            }
            break;
        }

        case 10:
            cout << "\nBFS Traversal\n";
            delivery.BFS(0);
            break;

        case 11:
            cout << "\nDFS Traversal\n";
            delivery.DFS(0);
            break;

        case 12:
            delivery.dijkstra(0);
            break;

        case 13: {
            if (orderQueue.empty()) {
                cout << "\nYour cart is empty.\n";
            } else {
                // Duplicate queue into a temporary container to read items without losing them
                queue<int> tempQueue = orderQueue;
                cout << "\n--- ITEMS IN YOUR CART ---\n";
                int itemNumber = 1;
                
                while (!tempQueue.empty()) {
                    int currentId = tempQueue.front();
                    tempQueue.pop();
                    
                    if (productMap.count(currentId)) {
                        Product p = productMap[currentId];
                        cout << itemNumber << ". " << p.name 
                             << " | ID: " << p.id 
                             << " | Rs." << p.price << endl;
                    }
                    itemNumber++;
                }
                cout << "---------------------------\n";
            }
            break;
        }

        case 14: {
            if (orderQueue.empty()) {
                cout << "\nYour cart is empty. Nothing to remove.\n";
            } else {
                int targetId;
                cout << "Enter Product ID to remove from cart: ";
                cin >> targetId;

                queue<int> updatedQueue;
                bool foundAndRemoved = false;

                // Rebuild the queue item by item, dropping the requested ID once
                while (!orderQueue.empty()) {
                    int currentId = orderQueue.front();
                    orderQueue.pop();

                    if (currentId == targetId && !foundAndRemoved) {
                        foundAndRemoved = true; 
                        cout << "Removed " << productMap[currentId].name << " from your cart.\n";
                    } else {
                        updatedQueue.push(currentId);
                    }
                }

                // Put everything back into main queue
                orderQueue = updatedQueue;

                if (!foundAndRemoved) {
                    cout << "Product ID " << targetId << " was not found in your cart.\n";
                }
            }
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 0);

    return 0;
}