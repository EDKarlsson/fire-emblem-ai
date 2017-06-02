# Fire Emblem Heroes AI
Project for making an AI to play Fire Emblem Heroes. Not intended to cheat the game but for me to learn about image processing and AI. Edit
Add topics

## Project Structure
Each sub directory will contain a readme with information about that module, what has been completed and what needs to be done. Some will contain notes, design implementations and resources / links / info for it.

---

Directory Structure
---
```
├── CMakeLists.txt
├── README.md
├── files
│   ├── Images
│   └── processed
└── src
    ├── Core
    ├── ImageProcessing
    └── main.cpp

```

## Overall TODO
1. ~~Implement image processor.~~
    1. I have a basic implementation for it completed.
2. Need to decide on how to interpret the information.
    1. Either have baseline images to compare against or use tesseract to perform OCR to extract the information.
3. BlueStack controller
    * Have some issues with
    1. Send Commands
    2. Take screenshots
