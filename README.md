# 🤖 AI-Powered Voice Assistant using ESP8266 and Gemini API *(In Progress)*

This project demonstrates how to build a smart voice assistant using an **ESP8266 microcontroller** and the **Gemini API** (from Google AI) to enable conversational capabilities in embedded devices.

> ✅ Current Status: The ESP8266 successfully sends text queries to the Gemini API and receives AI-generated responses over HTTPS. Microphone and speaker integration is in progress.

---

## 📌 Features

* 🔌 **ESP8266-based smart assistant** with Wi-Fi connectivity
* 🌐 **HTTPS communication** with Google Gemini API using Arduino libraries
* 🧠 Parses and displays AI responses on the Serial Monitor
* 📈 Lightweight and cost-effective alternative to traditional voice assistant devices
* 🎤 Planned: Integration of **microphone input** and **speaker output**

---

## 🧰 Tech Stack

* **Hardware:** ESP8266 NodeMCU
* **Programming Language:** C++ (Arduino)
* **Libraries Used:**

  * `ESP8266WiFi.h`
  * `WiFiClientSecure.h`
  * `ESP8266HTTPClient.h`
  * `ArduinoJson.h`
* **API:** [Gemini API](https://ai.google.dev)

---

## 🔁 How It Works

1. Connect ESP8266 to Wi-Fi
2. Wait for user input via Serial Monitor (text-based question)
3. Format the input as a JSON payload for Gemini API
4. Send the request using HTTPS and receive AI-generated response
5. Parse the JSON and print the answer
6. (In Progress) Output the answer through a speaker

---

## 📷 Demo (Text Mode)

```
User Input: What is the capital of Japan?
AI Output: The capital of Japan is Tokyo.
```

---

## 📦 Future Improvements

* 🎤 Add microphone (voice input)
* 🔊 Add speaker (audio output)
* 🖥️ Build a lightweight web interface for logging queries
* 💾 Add SD card logging for offline usage history

---

## 🧠 Learning Outcomes

* Embedded HTTPS requests and JSON parsing
* Real-time communication with LLM APIs
* Embedded + AI fusion: bridging smart software with low-power hardware

---

## 🙌 Contributions & Support

Feel free to fork, contribute, or suggest improvements via pull requests or issues!

---

## 📜 License

This project is for learning and experimentation purposes only. Not affiliated with Google or any AI provider.

---

## ✍️ Author

**Bareddy Dinesh Reddy**
[LinkedIn](https://www.linkedin.com/in/bareddy-dinesh-reddy/) | [GitHub](https://github.com/Dinesh18-2004)
