# Finance_tracker


A simple personal finance management system built using C and Data Structures. This program helps users track income, expenses, and bank balances efficiently using a doubly linked list.
It is quite simple for us students to lose track
of our expenditures because we use digital
currency for many transactions. To ensure
we don’t spend too much money, it is crucial
for us to keep track of our expenditures. And
this is the point at which our ϐinance tracker
is useful. Entering the transaction amount,
date, and category is all that is required. You
may also include a description for your
transaction! The amount that has been
credited and debited from your account is
displayed, together with the current balance
and the difference after all transactions.
Lastly, the transactions are arranged
according to their transaction sequence. We
have achieved these functions by storing
each of the transactions into a node and
sorting them using bubble sort. 
## ALGORITHMS AND DATA STRUCTURES USED
Data Structure used: Doubly linked list.
Sorting Algorithm used: Bubble Sort.
Doubly Linked List:
Structure of a Doubly Linked List:
1.Node: Each item in the list.
 A node holds:
 a. Data: The actual content, like a transaction
 b. Next Pointer: Points to the next node
 c. Previous Pointer: Points to the previous node.
2. Head: Points to the first node in the list.
3. Tail: Points to the last node in the list.
Doubly Linked List is Considered advanced for the
following reasons:
Two-way Navigation:
Each node in a doubly linked list contains
2 pointers (i.e. previous and next). With
the help of the 2 pointers, we can traverse
through the list in both forward and
backward directions. 
Enhanced Insertion and Deletion:
As each node has pointers pointing to the
next and the previous nodes, we don’t have
to traverse the entire list to find the
predecessor of a node during insertion and
deleting process and saves time.
Complexity in Implementation:
The implementation of a doubly linked list
is generally more complex than that of a
singly linked list. Developers must
manage additional pointers and ensure
proper linkage in both directions,
increasing the potential for errors if not
handled carefully.
Memory Overhead:
Each node requires additional memory for
the extra pointer, making doubly linked
lists more memory-intensive than singly
linked lists. 
Why Doubly Linked List for Finance Tracker??
Doubly Linked List is a good data structure for
finance tracker because each node stores
transaction details like date of transaction, amount,
credit/debit, category and description of the
transaction. The two-way navigation (forward and
backward) makes it flexible and efficient for
keeping record of all transactions.
- Adding Transactions is Easy: Each new
transaction just gets added to the end of the list,
which is quick and efficient.
- Sorting Transactions by Date: Since each node
links to the next and previous nodes, sorting by date
is easier to do.
- Viewing and Calculating Total: You can go
through the list easily to display transactions or
calculate totals, which makes it simple to see how
much you’ve spent or earned.
-Using Memory Efficiently: The list only uses
memory for the transactions entered, so it’s efficient
and doesn’t waste space. 

## 📌 Features
- Add Transactions: Record income and expenses.
- Sort Transactions: Organizes financial data efficiently.
- View Balance: Keeps track of updated account balance.
- Data Structures Used: Doubly Linked List for efficient insertions and deletions.
- Language: C
- Concepts Used: Data Structures (Doubly Linked List), File Handling

