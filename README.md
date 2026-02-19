# Hollow

A lightweight C++ core library designed for personal projects.

Note: This library is primarily intended for personal use and may not be suitable for general consumption.

## Features

- **Version Management** - Simple version tracking with semantic versioning utilities
- **Aurora Integration** - Colorful logging system with multiple log levels
- **Common Utilities** - Essential helper functions and classes
- **Lightweight** - Minimal dependencies and fast compilation
- **Modern C++** - Written with modern C++ standards in mind

## Quick Start

```cpp
#include "Hollow.hpp"

int main() {
    // Make Version constant with MAJOR, MINOR, PATCH, BUILD and relase type+
    // NOTE: version should be called <projectName>Version
	const Version hollowVersion(0, 0, 0, 0, ReleaseType::ALPHA);
    // Create Hollow instance and give it the version reference
    Hollow hollow(
        hollowVersion,
        "MyProject",
        Color(255, 100, 100)
    );
    
    // Get Aurora logger and log messages
    Aurora& logger = hollow.getAurora();
    logger.info("Hello from Hollow!");
    logger.warning("This is a warning");
    logger.error("Something went wrong");
    
    // Get version info
    auto version = hollow.getVersion();
    std::cout << "Hollow version: " << version.toString() << std::endl;
    
    return 0;
}
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author

Created and maintained by VerdantMoss (2026)