# Use an official C++ image with development tools
FROM gcc:latest

# Install dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    libglfw3-dev \
    libglew-dev \
    libglm-dev \
    libgl1-mesa-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libxxf86vm-dev \
    xorg-dev

# Create a working directory
WORKDIR /usr/src/app

# Copy the current directory contents into the container
COPY . .

# Create a build directory
RUN mkdir -p build

# Set the working directory to the build directory
WORKDIR /usr/src/app/build

# Configure the project with CMake and build it
RUN cmake .. && make

# Run the executable
CMD ["./intro_opengl"]