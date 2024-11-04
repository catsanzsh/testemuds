# testemuds
> req 11.3.24$
TesteMUDs

TesteMUDs is a collection of Multi-User Dungeon (MUD) games and tools designed to provide an engaging and interactive text-based multiplayer experience. Whether you're a developer looking to create your own MUD or a player seeking immersive adventures, TesteMUDs offers the resources and community support you need.

Table of Contents
Features
Installation
Usage
Contributing
Documentation
License
Contact
Acknowledgements
Features
Multi-User Support: Engage with players from around the world in real-time.
Customizable Worlds: Create and modify game worlds with ease.
Rich Text-Based Interface: Enjoy immersive storytelling and interactive gameplay.
Extensible Architecture: Easily add new features, commands, and modules.
Community Driven: Collaborate with a passionate community of developers and players.
Cross-Platform Compatibility: Run TesteMUDs on various operating systems, including macOS (M1), Windows, and Linux.
Installation
Prerequisites
C++ Compiler: Ensure you have a C++17 compatible compiler installed.
SDL2: Used for window management and event handling.
OpenGL: For rendering graphics.
GLM: OpenGL Mathematics library for vector and matrix operations.
CMake: For building the project.
macOS (M1)
Install Homebrew (if not already installed):

bash
Copy code
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
Install Dependencies:

bash
Copy code
brew install sdl2 glm cmake
Clone the Repository:

bash
Copy code
git clone https://github.com/catsanzsh/testemuds.git
cd testemuds
Build the Project:

bash
Copy code
mkdir build
cd build
cmake ..
make
Run the Application:

bash
Copy code
./TesteMUDs
Windows
Install Dependencies:

Download and install SDL2.
Download and install GLM.
Install CMake.
Clone the Repository:

bash
Copy code
git clone https://github.com/catsanzsh/testemuds.git
cd testemuds
Build the Project:

Open CMake and configure the project.
Generate the Visual Studio solution.
Open the solution in Visual Studio and build.
Run the Application:

Execute the generated .exe file from the build directory.
Linux
Install Dependencies:

bash
Copy code
sudo apt-get update
sudo apt-get install build-essential libsdl2-dev libglm-dev cmake
Clone the Repository:

bash
Copy code
git clone https://github.com/catsanzsh/testemuds.git
cd testemuds
Build the Project:

bash
Copy code
mkdir build
cd build
cmake ..
make
Run the Application:

bash
Copy code
./TesteMUDs
Usage
Starting the Server
Navigate to the server directory:

bash
Copy code
cd server
Build and run the server:

bash
Copy code
./TesteMUDs_Server
Connecting as a Player
Open the client application.

Enter the server's IP address and port number.

Start interacting with the game world!

In-Game Commands
look: Examine your surroundings.
move <direction>: Move in a specified direction (north, south, east, west).
say <message>: Communicate with other players.
inventory: View your items.
help: List all available commands.
Contributing
We welcome contributions from the community! To get started:

Fork the Repository

Create a Feature Branch

bash
Copy code
git checkout -b feature/YourFeature
Commit Your Changes

bash
Copy code
git commit -m "Add your feature"
Push to the Branch

bash
Copy code
git push origin feature/YourFeature
Open a Pull Request

Please ensure your code adheres to our Code of Conduct and Contribution Guidelines.

Documentation
Comprehensive documentation is available in the docs directory. It includes:

Setup Guides
API References
Tutorials
FAQ
Visit Documentation for more information.

License
This project is licensed under the Apache License.
 
Feel free to reach out with any questions, suggestions, or feedback!

Acknowledgements
SDL2: For providing robust multimedia handling.
GLM: For simplifying mathematical operations in OpenGL.
OpenGL Community: For extensive resources and support.
Contributors: Special thanks to all the contributors who have helped improve TesteMUDs.
Happy Gaming!
