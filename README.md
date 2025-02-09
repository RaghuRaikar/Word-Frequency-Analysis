📖 Word Frequency Analyzer
==========================

🔍 **Analyze and rank words from any text dataset!**

🛠 Purpose of the Program
-------------------------

This program is designed to analyze large text datasets by identifying **word frequencies** and ranking words based on **length, frequency, and lexicographic order**. Originally built for processing **Shakespeare's works**, it can be applied to **any structured text dataset** where words are stored line by line.

### 🔹 **Use Cases:**

✅ **Literary Analysis** -- Identify common themes in classic works like Shakespeare, Dickens, or Austen\
✅ **Data Processing** -- Extract and rank words from research papers, articles, or books\
✅ **Linguistic Research** -- Study word frequency distribution and text complexity\
✅ **Natural Language Processing (NLP) Preprocessing** -- Create structured datasets from raw text

This tool is particularly useful for **students, researchers, linguists, and developers** interested in **text analytics and computational linguistics**.

* * * * *

📌 Features
-----------

✅ **Custom-built linked list** for efficient word storage & retrieval\
✅ **Processes any text dataset** with words stored line-by-line\
✅ **Optimized ranking** based on frequency & lexicographic order\
✅ **Handles large files** with efficient memory usage\
✅ **Command-line interface (CLI)** for flexible input/output processing\
✅ **Makefile included** for easy compilation

* * * * *

🛠 How It Works
---------------

The program reads a **cleaned text file**, where each line contains a **single lowercase word**. It then:\
🔹 **Stores words & their frequencies** in a linked list (no built-in lists or arrays)\
🔹 **Processes user queries** to find the most frequent words of a given length\
🔹 **Outputs results** based on ranking & lexicographic order

* * * * *

🔍 Understanding the Input & Output
-----------------------------------

### 📥 **Input File (e.g., `simple-input.txt`)**

Each line in the input file contains **two numbers**:\
1️⃣ **Word length** -- Filters words of a specific length\
2️⃣ **Rank (0-based)** -- Returns the word at that rank based on **frequency & lexicographic order**

📌 **Example Input (`simple-input.txt`):**

`6 3`  
`10 0`  
`9 2`  
`8 14`  
`8 15`  
`26 0`  

* * * * *

### 📤 **Output File (e.g., `simple-output.txt`)**

Each line in the output file contains a **single word** matching the input query, or `-` if no word is found.

📌 **Example Output (`simple-output.txt`):**

`father`  
`gloucester`  
`messenger`  
`business`  
`personal`  
`-`  

* * * * *

### 📌 **How to Interpret the Output:**

-   **"father"** → The **4th most frequent word** (rank 3) with **6 letters**
-   **"gloucester"** → The **most frequent word** (rank 0) with **10 letters**
-   **"business"** and **"personal"** have the **same frequency**, but **"business"** appears first lexicographically
-   **"-"** → No word exists for that query (e.g., Shakespeare never used a word with 26 letters)

* * * * *

🔄 Supports Any Dataset
-----------------------

While this program was tested with **Shakespeare's works**, it can analyze **any** dataset formatted as:

`word1
word2
word3
...`

Simply **replace `shakespeare-cleaned5.txt`** with any **cleaned** text dataset.

* * * * *

🚀 Performance & Constraints
----------------------------

⚡ **Optimized Execution:**

-   Handles **up to 200 queries** in **under 2 minutes**
-   Uses **efficient linked list operations** for quick lookups
-   **Memory-efficient** design for large datasets

🔹 **Error Handling:**

-   If no word of the given length exists, it returns `-`
-   If multiple words share the same frequency, they are ranked **alphabetically**

* * * * *

📦 Installation & Usage
-----------------------

### 📥 1. Clone the Repository

`git clone https://github.com/your-repo/word-analyzer.git`  
`cd word-analyzer`

### 🏗 2. Build the Program

`make`

This will create an **executable** named `bard`.

### ▶️ 3. Run the Program

`./bard simple-input.txt simple-output.txt`

📌 **Explanation:**

-   `simple-input.txt` contains **query pairs** (word length & rank).
-   `simple-output.txt` stores the **generated results**.
-   **To use your own dataset**, replace `shakespeare-cleaned5.txt` with a **custom dataset** following the same structure.

* * * * *

📂 File Structure
-----------------

- 📂 word-analyzer
- ├── 📄 Makefile               # Automates compilation
- ├── 📄 bard.cpp               # Main program logic
- ├── 📄 linkedlist.cpp         # Custom linked list implementation
- ├── 📄 linkedlist.h           # Linked list header file
- ├── 📄 shakespeare-cleaned5.txt # Cleaned text dataset
- ├── 📄 simple-input.txt       # Sample input queries
- ├── 📄 simple-output.txt      # Generated output
- ├── 📄 README.md              # This file`

* * * * *

🎯 Algorithm Overview
---------------------

1️⃣ **Read and Parse Words**\
2️⃣ **Store Words in a Linked List**\
3️⃣ **Count Frequencies Efficiently**\
4️⃣ **Process Queries in Optimized Order**\
5️⃣ **Output Results in Expected Format**

* * * * *

📜 Fun Facts from the Shakespeare Dataset!
------------------------------------------

🎭 **Longest Word:** *honorificabilitudinitatibus*\
🧛 **Creepiest Word?** *anthropophaginian* (a cannibal!)\
🤴 **"Caesar" appears more than "Brutus"**

* * * * *

💡 Want to Improve It?
----------------------

🔹 **Implement trie structures** for even faster lookups\
🔹 **Expand beyond Shakespeare** to analyze **other classic texts**\
🔹 **Optimize further** with **hashmaps & AVL trees**

* * * * *

🏆 Built With
-------------

🔹 **C/C++** for efficiency\
🔹 **Custom Linked List** (No built-in structures allowed!)\
🔹 **Makefile** for seamless compilation
