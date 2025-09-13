#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// Class to represent an image as a 3D matrix
class Image {
private:
    int width, height, maxVal, channels;
    vector<vector<vector<int>>> data; // [height][width][channel]

public:
    // Default constructor
    Image() {
        width = 0;
        height = 0;
        maxVal = 255;
        channels = 3;
    }
    
    // Create blank image
    Image(int w, int h, int ch = 3) {
        width = w;
        height = h;
        maxVal = 255;
        channels = ch;
        data.resize(height, vector<vector<int>>(width, vector<int>(channels, 0)));
    }
    
    // Get image dimensions
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getChannels() const { return channels; }
    
    // Set number of channels
    void setChannels(int ch) { 
        channels = ch;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                data[y][x].resize(channels, 0);
            }
        }
    }
    
    // Pixel access
    int& operator()(int y, int x, int channel) {
        return data[y][x][channel];
    }
    
    const int& operator()(int y, int x, int channel) const {
        return data[y][x][channel];
    }
    
    // Load PPM image (P3 format)
    bool loadPPM(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return false;
        }
        
        string format;
        file >> format;
        if (format != "P3") {
            cerr << "Error: Only P3 PPM format is supported" << endl;
            return false;
        }
        
        file >> width >> height >> maxVal;
        channels = 3;
        data.resize(height, vector<vector<int>>(width, vector<int>(channels, 0)));
        
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                for (int c = 0; c < channels; c++) {
                    file >> data[y][x][c];
                }
            }
        }
        
        file.close();
        return true;
    }
    
    // Save PPM image (P3 format)
    bool savePPM(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not create file " << filename << endl;
            return false;
        }
        
        file << "P3\n" << width << " " << height << "\n" << maxVal << "\n";
        
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (channels == 1) {
                    // For grayscale images, write the same value for all three channels
                    int gray = data[y][x][0];
                    file << gray << " " << gray << " " << gray << " ";
                } else {
                    // For color images, write all three channels
                    for (int c = 0; c < 3; c++) {
                        file << data[y][x][c] << " ";
                    }
                }
            }
            file << "\n";
        }
        
        file.close();
        return true;
    }
    
    // Print image data to console (for small images)
    void print() const {
        cout << "Image " << width << "x" << height << " (" << channels << " channels):\n";
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cout << "(";
                for (int c = 0; c < channels; c++) {
                    cout << data[y][x][c];
                    if (c < channels - 1) cout << ",";
                }
                cout << ") ";
            }
            cout << endl;
        }
    }
};

/**
 * Converts a color image to grayscale
 * 
 * Steps:
 * 1. Create a new single-channel image with the same width and height
 * 2. For each pixel in the input image:
 *    - Get the R, G, and B values
 *    - Calculate the grayscale value using the formula: 
 *        gray = 0.299 * R + 0.587 * G + 0.114 * B
 *    - Set the grayscale value in the output image
 * 3. Return the grayscale image
 */
Image convertToGrayscale(const Image& input) {
    int height = input.getHeight();
    int width = input.getWidth();
    Image output(width, height, 1); // Single channel for grayscale
    
    // TODO: Implement this function
    // For each pixel:
    //   Get R, G, B values from input image
    //   Calculate gray = 0.299*R + 0.587*G + 0.114*B
    //   Set output(y, x, 0) = gray
    
    return output;
}

/**
 * Flips image horizontally (left to right)
 * 
 * Steps:
 * 1. Create a new image with the same dimensions as the input
 * 2. For each pixel in the input image:
 *    - Copy the pixel from position (y, x) in the input
 *    - To position (y, width - 1 - x) in the output
 * 3. Return the flipped image
 */
Image flipHorizontal(const Image& input) {
    int height = input.getHeight();
    int width = input.getWidth();
    int channels = input.getChannels();
    Image output(width, height, channels);
    
    // TODO: Implement this function
    // For each pixel and each channel:
    //   output(y, width-1-x, c) = input(y, x, c)
    
    return output;
}

/**
 * Flips image vertically (top to bottom)
 * 
 * Steps:
 * 1. Create a new image with the same dimensions as the input
 * 2. For each pixel in the input image:
 *    - Copy the pixel from position (y, x) in the input
 *    - To position (height - 1 - y, x) in the output
 * 3. Return the flipped image
 */
Image flipVertical(const Image& input) {
    int height = input.getHeight();
    int width = input.getWidth();
    int channels = input.getChannels();
    Image output(width, height, channels);
    
    // TODO: Implement this function
    // For each pixel and each channel:
    //   output(height-1-y, x, c) = input(y, x, c)
    
    return output;
}

/**
 * Adjusts image brightness
 * 
 * Steps:
 * 1. Create a new image with the same dimensions as the input
 * 2. For each pixel and each color channel:
 *    - Add the brightness value to the pixel value
 *    - Clamp the result between 0 and 255
 * 3. Return the adjusted image
 */
Image adjustBrightness(const Image& input, int value) {
    int height = input.getHeight();
    int width = input.getWidth();
    int channels = input.getChannels();
    Image output(width, height, channels);
    
    // TODO: Implement this function
    // For each pixel and each channel:
    //   new_value = input(y, x, c) + value
    //   output(y, x, c) = max(0, min(255, new_value))
    
    return output;
}

/**
 * Adjusts image contrast
 * 
 * Steps:
 * 1. Create a new image with the same dimensions as the input
 * 2. For each pixel and each color channel:
 *    - Subtract 128 from the pixel value to center around 0
 *    - Multiply by the contrast factor
 *    - Add 128 to center back around 128
 *    - Clamp the result between 0 and 255
 * 3. Return the adjusted image
 */
Image adjustContrast(const Image& input, float factor) {
    int height = input.getHeight();
    int width = input.getWidth();
    int channels = input.getChannels();
    Image output(width, height, channels);
    
    // TODO: Implement this function
    // For each pixel and each channel:
    //   new_value = factor * (input(y, x, c) - 128) + 128
    //   output(y, x, c) = max(0, min(255, new_value))
    
    return output;
}

/**
 * Applies a simple blur filter
 * 
 * Steps:
 * 1. Create a new image with the same dimensions as the input
 * 2. For each pixel (excluding borders):
 *    - For each color channel:
 *        - Calculate the average of the 3x3 neighborhood
 *        - Set the output pixel to this average value
 * 3. Return the blurred image
 */
Image applyBlur(const Image& input) {
    int height = input.getHeight();
    int width = input.getWidth();
    int channels = input.getChannels();
    Image output(width, height, channels);
    
    // TODO: Implement this function
    // For each pixel (from y=1 to height-2, x=1 to width-2) and each channel:
    //   sum = 0
    //   For each neighbor (ky from -1 to 1, kx from -1 to 1):
    //     sum += input(y+ky, x+kx, c)
    //   output(y, x, c) = sum / 9
    
    return output;
}

/**
 * Rotates image 90 degrees clockwise
 * 
 * Steps:
 * 1. Create a new image with swapped dimensions (height becomes width, width becomes height)
 * 2. For each pixel in the input image:
 *    - Copy the pixel from position (y, x) in the input
 *    - To position (x, height - 1 - y) in the output
 * 3. Return the rotated image
 */
Image rotate90(const Image& input) {
    int height = input.getHeight();
    int width = input.getWidth();
    int channels = input.getChannels();
    Image output(height, width, channels); // Width and height are swapped
    
    // TODO: Implement this function
    // For each pixel and each channel:
    //   output(x, height-1-y, c) = input(y, x, c)
    
    return output;
}

// Creates a simple 4x4 test image with a pattern
void createTestImage(const string& filename) {
    Image img(4, 4);
    
    // Create a simple 4x4 pattern
    // Row 0
    img(0, 0, 0) = 255; img(0, 0, 1) = 0;   img(0, 0, 2) = 0;    // Red
    img(0, 1, 0) = 0;   img(0, 1, 1) = 255; img(0, 1, 2) = 0;    // Green
    img(0, 2, 0) = 0;   img(0, 2, 1) = 0;   img(0, 2, 2) = 255;  // Blue
    img(0, 3, 0) = 255; img(0, 3, 1) = 255; img(0, 3, 2) = 255;  // White
    
    // Row 1
    img(1, 0, 0) = 255; img(1, 0, 1) = 255; img(1, 0, 2) = 0;    // Yellow
    img(1, 1, 0) = 255; img(1, 1, 1) = 0;   img(1, 1, 2) = 255;  // Magenta
    img(1, 2, 0) = 0;   img(1, 2, 1) = 255; img(1, 2, 2) = 255;  // Cyan
    img(1, 3, 0) = 128; img(1, 3, 1) = 128; img(1, 3, 2) = 128;  // Gray
    
    // Row 2
    img(2, 0, 0) = 255; img(2, 0, 1) = 128; img(2, 0, 2) = 0;    // Orange
    img(2, 1, 0) = 128; img(2, 1, 1) = 255; img(2, 1, 2) = 0;    // Light Green
    img(2, 2, 0) = 128; img(2, 2, 1) = 0;   img(2, 2, 2) = 255;  // Purple
    img(2, 3, 0) = 255; img(2, 3, 1) = 128; img(2, 3, 2) = 128;  // Pink
    
    // Row 3
    img(3, 0, 0) = 128; img(3, 0, 1) = 255; img(3, 0, 2) = 128;  // Light Green
    img(3, 1, 0) = 128; img(3, 1, 1) = 128; img(3, 1, 2) = 255;  // Light Blue
    img(3, 2, 0) = 255; img(3, 2, 1) = 255; img(3, 2, 2) = 128;  // Light Yellow
    img(3, 3, 0) = 0;   img(3, 3, 1) = 0;   img(3, 3, 2) = 0;    // Black
    
    img.savePPM(filename);
    cout << "Created 4x4 test image: " << filename << endl;
    
    // Print the image data to console
    cout << "\nOriginal image data:\n";
    img.print();
}

int main() {
    cout << "Image Processing with Matrices - Student Project\n";
    cout << "================================================\n\n";
    
    // Create a 4x4 test image
    createTestImage("test_image.ppm");
    
    // Load the image
    Image input;
    if (!input.loadPPM("test_image.ppm")) {
        cerr << "Failed to load image. Exiting.\n";
        return 1;
    }
    
    cout << "\nImage loaded successfully. Dimensions: " 
              << input.getWidth() << "x" << input.getHeight() << "\n\n";
    
    // Apply various transformations
    cout << "Applying image transformations...\n";
    
    Image gray = convertToGrayscale(input);
    gray.savePPM("gray_image.ppm");
    cout << "- Grayscale conversion completed\n";
    cout << "Grayscale image data:\n";
    gray.print();
    cout << endl;
    
    Image flippedH = flipHorizontal(input);
    flippedH.savePPM("flipped_horizontal.ppm");
    cout << "- Horizontal flip completed\n";
    cout << "Horizontally flipped image data:\n";
    flippedH.print();
    cout << endl;
    
    Image flippedV = flipVertical(input);
    flippedV.savePPM("flipped_vertical.ppm");
    cout << "- Vertical flip completed\n";
    cout << "Vertically flipped image data:\n";
    flippedV.print();
    cout << endl;
    
    Image bright = adjustBrightness(input, 50);
    bright.savePPM("bright_image.ppm");
    cout << "- Brightness adjustment completed\n";
    cout << "Brightness adjusted image data:\n";
    bright.print();
    cout << endl;
    
    Image contrast = adjustContrast(input, 1.5f);
    contrast.savePPM("contrast_image.ppm");
    cout << "- Contrast adjustment completed\n";
    cout << "Contrast adjusted image data:\n";
    contrast.print();
    cout << endl;
    
    Image blur = applyBlur(input);
    blur.savePPM("blurred_image.ppm");
    cout << "- Blur filter completed\n";
    cout << "Blurred image data:\n";
    blur.print();
    cout << endl;
    
    Image rotated = rotate90(input);
    rotated.savePPM("rotated90_image.ppm");
    cout << "- 90-degree rotation completed\n";
    cout << "Rotated image data:\n";
    rotated.print();
    cout << endl;
    
    cout << "\nAll operations completed successfully!\n";
    cout << "Check the generated PPM files to see the results.\n";
    cout << "Use an image viewer that supports PPM format or convert them to PNG/JPG.\n";
    
    return 0;
}