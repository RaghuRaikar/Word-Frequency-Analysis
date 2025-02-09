📖 **Word Frequency Analyzer**
==============================

🚀 **Analyze and rank words from any text dataset!**

This program efficiently processes **large text files**, identifies word frequencies, and ranks them based on **length, frequency, and lexicographic order**. Currently analyzes **Shakespeare's works**, but it can handle **any cleaned text dataset** where words are separated by new lines.

* * * * *

📌 **Features**
---------------

✅ **Custom-built linked list** for efficient word storage and retrieval\
✅ **Processes any text dataset** with words stored line-by-line\
✅ **Fast word ranking by frequency & lexicographic order**\
✅ **Handles large files with optimized memory usage**\
✅ **Command-line interface (CLI) for flexible input/output processing**\
✅ **Makefile for automated compilation**

* * * * *

🛠 **How It Works**
-------------------

This program reads a **cleaned text file**, where each line contains a single lowercase word.\
It then:\
🔹 **Stores words & their frequencies** in a linked list (no built-in lists or arrays)\
🔹 **Processes user queries** to find the most frequent words of a given length\
🔹 **Outputs results** based on ranking & lexicographic order

### 🔍 **Example Input (Shakespeare's Dataset)**

Each query consists of two numbers:

-   The **word length** to filter words
-   The **rank** (0-based) of the word sorted by frequency

📌 **Query File (`input.txt`):**


`6 3
10 0
9 2
8 14
8 15
26 0`

📌 **Generated Output (`output.txt`):**

`father
gloucester
messenger
business
personal
-`

-   `"gloucester"` is the **most frequent word** of **10 letters**
-   `"business"` and `"personal"` have the **same frequency**, but `"business"` appears **earlier lexicographically**
-   `"-"` means **no matching word found**

### 🔄 **Supports Any Dataset**

While this program was tested with **Shakespeare's works**, it can analyze **any dataset** formatted as:

`word1
word2
word3
...`

Just replace the input file with your own **cleaned text dataset**.

* * * * *

🚀 **Performance & Constraints**
--------------------------------

⚡ **Optimized Execution:**

-   Handles up to **200 queries in under 2 minutes**
-   Uses **efficient linked list operations** for quick lookups
-   Memory-efficient design for **large datasets**

🔹 **Error Handling:**

-   If no word of the given length exists, it **returns `'-'`**
-   If multiple words share the same frequency, they are ranked **alphabetically**

* * * * *

📦 **Installation & Usage**
---------------------------

### 📥 **1\. Clone the Repository**


`git clone https://github.com/your-repo/word-analyzer.git`  
`cd word-analyzer`

### 🏗 **2\. Build the Program**

`make`

This creates an executable named `bard`.

### ▶️ **3\. Run the Program**

`./bard input.txt output.txt`

-   `input.txt` contains **query pairs** (word length & rank).
-   `output.txt` stores the generated results.

🔹 **To use your own dataset**, replace `input.txt` with a **custom dataset** following the same structure.

* * * * *

📂 **File Structure**
---------------------

`📂 word-analyzer
 ├── 📄 Makefile       # Automates compilation
 ├── 📄 bard.cpp       # Main program logic
 ├── 📄 linkedlist.h   # Custom linked list implementation
 ├── 📄 input.txt      # Sample input queries
 ├── 📄 output.txt     # Generated output
 ├── 📄 README.md      # This file`

* * * * *

🎯 **Algorithm Overview**
-------------------------

1️⃣ **Read and Parse Words**\
2️⃣ **Store Words in a Linked List**\
3️⃣ **Count Frequencies Efficiently**\
4️⃣ **Process Queries in Optimized Order**\
5️⃣ **Output Results in Expected Format**

* * * * *

📜 **Fun Facts from the Shakespeare Dataset!**
----------------------------------------------

🎭 **Longest Word:** *honorificabilitudinitatibus*\
🧛 **Creepiest Word?** *anthropophaginian* (a cannibal!)\
🤴 **"Caesar" appears more than "Brutus"**

* * * * *

🚀 **Releases & Demo**
----------------------

📽 **Watch the program in action!** [👉 Check out the latest release](https://github.com/your-repo/word-analyzer/releases)

💡 **To include `.mov` demo in README**:

-   Upload your `.mov` file as part of a **GitHub Release**
-   Add a link to the **Release Page** in this section

* * * * *

### 💡 **Want to Improve It?**

-   Implement **trie structures** for even faster lookups
-   Expand **beyond Shakespeare** to analyze other classic texts
-   Optimize further with **hashmaps & AVL trees**

* * * * *

### 🏆 **Built With**

🔹 **C/C++** for efficiency\
🔹 **Custom Linked List** (No built-in structures allowed!)\
🔹 **Makefile** for seamless compilation

* * * * *

🔥 **Get Started Today!**\
📩 **Questions?** Open an [Issue](https://github.com/your-repo/word-analyzer/issues) or Fork & Improve!

* * * * *

**✨ A powerful tool for text analysis---fast, efficient, and expandable! ✨**
