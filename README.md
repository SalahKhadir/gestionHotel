# HotelPlus Management System

A comprehensive C++ console application for managing hotel operations, including client management, room bookings, and reservation handling.

## Features

- **Client Management**
  - Add new clients with personal details
  - View client information using client ID
  - Store client data including name, surname, and address

- **Room Management**
  - Add new rooms to the hotel inventory
  - View room details and availability
  - Track room phone numbers

- **Reservation System**
  - Create new reservations
  - View reservation details
  - Delete existing reservations
  - Update reservation information
  - Date-based booking management

## Technical Details

### Prerequisites
- C++ compiler (supporting C++11 or later)
- Standard Template Library (STL)
- Make or CMake (for building)

### Project Structure
```
HotelPlus/
├── src/
│   ├── main.cpp
│   ├── client.h
│   ├── chambre.h
│   └── reservation.h
├── README.md
└── CMakeLists.txt
```

### Classes
- `Client`: Manages client information
- `Chambre`: Handles room details
- `Reservation`: Controls booking operations

## Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/hotelplus.git
```

2. Navigate to the project directory:
```bash
cd hotelplus
```

3. Build the project:
```bash
mkdir build
cd build
cmake ..
make
```

## Usage

1. Run the executable:
```bash
./hotelplus
```

2. Navigate through the menus:
   - Use the main menu to access different modules
   - Follow the prompts to perform desired operations
   - Enter '0' to return to the previous menu

## Menu Structure

1. **Main Menu**
   - Client Management
   - Room Management
   - Reservation Management

2. **Client Menu**
   - Add new client
   - Display client information

3. **Room Menu**
   - Add new room
   - Display room information

4. **Reservation Menu**
   - Create reservation
   - View reservation details
   - Delete reservation
   - Modify reservation

## Contributing

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author

[Your Name]

## Acknowledgments

- Built as a practical implementation of hotel management systems
- Designed for educational purposes and real-world applications
- Inspired by the need for efficient hotel booking management
