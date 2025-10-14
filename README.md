# 🚀 TerraTrack
```
"""
AI-powered robotics project inspired by the game TerraTech.
Built for learning, experimentation, and competition.
"""
```

![onshapesketch.png](https://github.com/femurdev/TerraTrack/blob/main/gallary/onshapesketch.png?raw=true)



## 🧠 Overview

TerraTrack is an ongoing robotics project that explores the intersection of **AI**, **embedded systems**, and **mechanical design**.  
The goal is to create a modular, intelligent platform capable of running on both **ESP32** and the upcoming **Arduino × Qualcomm** systems.

While some design details are being kept private until the competition season wraps up, this repository captures the learning process, designs, and build journey so far.


## ⚙️ Current Focus

- 🤖 Basic AI-driven motion and control (early stage)
- ⚡ Compatibility across ESP32 and Arduino hardware
- 🧩 Modular mechanical design for quick rebuilds
- 🔧 Open workflow using Onshape + Blender
- 🔋 Safe custom power system with 3D-printed enclosure


## 🛠️ Build Journal

Read the full project journal on **Hack Club Blueprint**:  
👉 [TerraTrack Project Journal](https://blueprint.hackclub.com/projects/485)

Below is a summary of progress so far.


### 🧩 Early Prototyping (v1–v2)
- Designed and printed first chassis, gearbox, and axles using **Onshape** and **Blender**.
- Fought with 3D printers, burned out an early prototype, and learned about safe wiring.
- Added a toggle switch after discovering how easy it is to cause “accidental smoke.”


### ⚙️ Iteration & Redesign (v3–v4)
- Reinforced axles with skateboard bearings to prevent snapping.
- Added gearbox covers and improved weight distribution.
- Created a new battery pack with secure housing.
- Introduced a rear “butt” assembly for smoother movement.
- Countless printing and soldering sessions to get it all together.


### 🔥 Failure, Fatigue, and Fire
- Motor drivers finally responded after days of debugging—then failed again.
- Tried increasing torque through firmware; resulted in actual smoke.
- Damaged stepper motors and drivers, currently sourcing replacements.
- Despite the setbacks, communication and control logic now partially work.


## 🧰 Tools & Components

| Category | Tools / Components |
|-----------|--------------------|
| CAD / Modeling | Onshape, Blender |
| Hardware | ESP32, TMC2209 Motor Drivers, Stepper Motors |
| Fabrication | 3D Printing (Da Vinci Jr., Bambu X1), Soldering |
| Software | Arduino IDE, C++ |
| Other | PLA Filament, Custom Battery Enclosure, Bearings |


## 💡 Lessons Learned

- Iteration is everything — no version is wasted.
- Documentation helps recover from mistakes faster.
- Always isolate power before soldering or testing.
- Fire safety isn’t optional.
- Building with limited resources teaches patience (and creativity).


## 🧭 Next Steps

- Rebuild chassis with stronger materials.
- Improve torque and motor control code.
- Add modular battery swapping and safety systems.
- Integrate AI motion logic once hardware is stable.
- Seek funding for replacement parts (~$120 total).


## 📷 Gallery

| Stage | Image |
|--------|--------|
| Gearbox v2 | ![Screenshot 2025-10-13 at 6.09.27 PM.png](https://blueprint.hackclub.com/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjEwMywicHVyIjoiYmxvYl9pZCJ9fQ==--5ce81054dadda8320fc72e035bf6d243b317185d/Screenshot%202025-10-13%20at%206.09.27%E2%80%AFPM.png) |
| Battery Pack v1 | ![battery1.jpeg](https://blueprint.hackclub.com/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjEyOCwicHVyIjoiYmxvYl9pZCJ9fQ==--9344d516bb8165549ce07e4c68c8ab4fa47640db/battery1.jpeg) |
| Gearbox Rebuild | ![Screenshot 2025-10-13 at 9.15.03 PM.png](https://blueprint.hackclub.com/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjEzMywicHVyIjoiYmxvYl9pZCJ9fQ==--8985d672864fac0d97f18e1149e35b02836ee922/Screenshot%202025-10-13%20at%209.15.03%E2%80%AFPM.png) |
| Final v2 Mockup | ![recreation.jpeg](https://blueprint.hackclub.com/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE0MywicHVyIjoiYmxvYl9pZCJ9fQ==--127a0d9994ebd72d4a93cb916e200d3cc7e1e544/recreation.jpeg) |


## 💬 Author

TerraTrack is a student robotics project developed as part of a Hack Club event.  
The aim is to learn, experiment, and document the process honestly — including the mistakes, smoke, and all.  

Follow progress or share ideas via [Hack Club Blueprint](https://blueprint.hackclub.com/projects/485).


## ⚠️ Note

Some key parts of the system are withheld until after the competition season to prevent duplication.  
Full technical documentation will be released once the event concludes.
