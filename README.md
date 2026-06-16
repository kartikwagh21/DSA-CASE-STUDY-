# DSA-CASE-STUDY-
# Smart E-Commerce Recommendation & Order Processing Platform

## 2.1 Project Title

Smart E-Commerce Recommendation & Order Processing Platform

## 2.2 Problem Statement

Develop a C++ based e-commerce system that manages products, processes customer orders, recommends popular products, and optimizes delivery routes using Data Structures and Algorithms.

## 2.3 Objectives

* Manage product catalog efficiently.
* Process customer orders using Queue.
* Recommend products based on popularity.
* Provide fast product search and lookup.
* Support order modification and undo operations.
* Optimize delivery routes using Graph algorithms.

## 2.4 System Overview / Architecture

User → Product Management → Order Processing → Delivery Network

Modules:

* Product Catalog (BST & AVL)
* Product Search (Binary Search & Hashing)
* Order Management (Queue)
* Undo Operations (Stack)
* Delivery Network (Graph, BFS, DFS, Dijkstra)

## 2.5 Data Structures and Algorithms Used

| Component        | DSA Used           |
| ---------------- | ------------------ |
| Product Storage  | BST, AVL Tree      |
| Product Search   | Binary Search      |
| Fast Lookup      | Hashing            |
| Order Processing | Queue              |
| Undo Operation   | Stack              |
| Recommendations  | Sorting            |
| Delivery Network | Graph              |
| Route Analysis   | BFS, DFS           |
| Shortest Route   | Dijkstra Algorithm |

## 2.6 Implementation Approach

1. Create product catalog.
2. Store products in BST, AVL Tree, and Hash Map.
3. Sort products by popularity for recommendations.
4. Search products using Binary Search.
5. Process orders using Queue.
6. Manage modifications using Stack.
7. Analyze delivery routes using BFS, DFS, and Dijkstra Algorithm.

## 2.7 Time and Space Complexity Analysis

| Operation        | Complexity   |
| ---------------- | ------------ |
| Hash Lookup      | O(1)         |
| BST Search       | O(log n)     |
| AVL Search       | O(log n)     |
| Queue Operations | O(1)         |
| Stack Operations | O(1)         |
| BFS              | O(V + E)     |
| DFS              | O(V + E)     |
| Dijkstra         | O((V+E)logV) |

Space Complexity:

* BST: O(n)
* AVL: O(n)
* Queue: O(n)
* Stack: O(n)
* Graph: O(V+E)

## 2.8 Execution Steps

### Compile

```bash
g++ final.cpp -o ecommerce
```

### Run

```bash
./ecommerce
```

Select options from the menu to perform different operations.

## 2.9 Sample Inputs and Outputs

### Search Product

Input:

```
4
101
```

Output:

```
Product Found
ID: 101
Name: Laptop
Price: Rs.75000
```

### Fast Lookup

Input:

```
5
108
```

Output:

```
Hash Lookup Successful
Monitor | Rs.12000
```

### Shortest Route

Input:

```
12
```

Output:

```
Warehouse -> 0 = 0
Warehouse -> 1 = 10
Warehouse -> 2 = 5
Warehouse -> 3 = 8
Warehouse -> 4 = 9
```

## 2.10 Screenshots

Include screenshots of:

* Main Menu
  
  <img width="353" height="237" alt="Screenshot 2026-06-16 at 10 45 36 PM" src="https://github.com/user-attachments/assets/c92a8357-72d6-4124-b81d-92a72a6c44a2" />






* BST Product Catalog
  
  <img width="379" height="152" alt="Screenshot 2026-06-16 at 10 45 49 PM" src="https://github.com/user-attachments/assets/d0d75821-7dee-4553-a014-5941fd4f309b" />

  

* AVL Product Catalog
  
  <img width="352" height="154" alt="Screenshot 2026-06-16 at 10 46 05 PM" src="https://github.com/user-attachments/assets/f5cb0f72-bae0-4084-b91f-e14f3ce28fe2" />




* Product Search
  
   <img width="208" height="106" alt="Screenshot 2026-06-16 at 10 49 34 PM" src="https://github.com/user-attachments/assets/e6a8792b-a0ac-4f59-a728-009e09952505" />



* Hash Lookup
  
  <img width="174" height="78" alt="Screenshot 2026-06-16 at 10 50 36 PM" src="https://github.com/user-attachments/assets/16f0bb21-c5fb-4776-bd53-df3cc66d64b5" />

 

* Product Recommendations

  <img width="226" height="131" alt="Screenshot 2026-06-16 at 10 54 12 PM" src="https://github.com/user-attachments/assets/050f2412-5877-4d6e-a6a4-0322bceed02a" />



  
* Order Processing
  
  <img width="398" height="546" alt="Screenshot 2026-06-16 at 10 55 53 PM" src="https://github.com/user-attachments/assets/0a70a5a5-5a84-4c89-a1ec-8fc58acc9fea" />








* BFS Traversal
  
  <img width="191" height="58" alt="Screenshot 2026-06-16 at 10 56 42 PM" src="https://github.com/user-attachments/assets/798fb84d-7d24-4928-aa85-184085fb35c5" />

  

* DFS Traversal

  <img width="184" height="69" alt="Screenshot 2026-06-16 at 10 57 45 PM" src="https://github.com/user-attachments/assets/a93ba318-c486-4809-b764-5dce3847fde9" />


  

* Dijkstra Output
  
  <img width="255" height="159" alt="Screenshot 2026-06-16 at 10 58 26 PM" src="https://github.com/user-attachments/assets/0a6d8ea2-a1a4-413c-97f9-7e7d3543a02d" />





## 2.11 Results and Observations

### Results

* Product records stored successfully.
* Fast product retrieval using Hashing.
* Efficient order processing using Queue.
* Delivery routes optimized using Dijkstra Algorithm.


### Observations

* Hashing provides the fastest lookup.
* AVL Tree performs better than BST for large datasets.
* Queue is suitable for FIFO order processing.
* Stack efficiently supports undo functionality.

## 2.12 Conclusion

The project successfully demonstrates the practical use of Data Structures and Algorithms in an e-commerce platform. BST, AVL Tree, Queue, Stack, Hashing, BFS, DFS, and Dijkstra Algorithm improve product management, order processing, recommendation generation, and delivery route optimization.
