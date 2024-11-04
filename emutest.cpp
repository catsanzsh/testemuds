// main.cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Emulator.h"
#include "HUD.h"
#include "WiFi.h"

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Function to initialize SDL and TTF
bool initSDL(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return false;
    }

    if (TTF_Init() == -1) {
        SDL_Log("TTF could not initialize! SDL_ttf Error: %s", TTF_GetError());
        return false;
    }

    *window = SDL_CreateWindow("NDS Emulator",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);
    if (*window == nullptr) {
        SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == nullptr) {
        SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
        return false;
    }

    return true;
}

// Function to display WiFi Settings Dialog
bool showWiFiSettings(SDL_Renderer* renderer, WiFi& wifi, TTF_Font* font) {
    // Simple text input for SSID and Password
    // For demonstration purposes, we'll simulate input
    // Implementing full text input in SDL2 requires handling keyboard events
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Display instructions
    SDL_Color White = {255, 255, 255};
    SDL_Surface* ssidSurface = TTF_RenderText_Solid(font, "Enter SSID: example_wifi", White);
    SDL_Texture* ssidTexture = SDL_CreateTextureFromSurface(renderer, ssidSurface);
    SDL_Rect ssidRect = {50, 50, ssidSurface->w, ssidSurface->h};
    SDL_RenderCopy(renderer, ssidTexture, NULL, &ssidRect);
    SDL_FreeSurface(ssidSurface);
    SDL_DestroyTexture(ssidTexture);

    SDL_Surface* passSurface = TTF_RenderText_Solid(font, "Enter Password: example_pass", White);
    SDL_Texture* passTexture = SDL_CreateTextureFromSurface(renderer, passSurface);
    SDL_Rect passRect = {50, 100, passSurface->w, passSurface->h};
    SDL_RenderCopy(renderer, passTexture, NULL, &passRect);
    SDL_FreeSurface(passSurface);
    SDL_DestroyTexture(passTexture);

    SDL_RenderPresent(renderer);
    SDL_Delay(2000); // Simulate user input delay

    // Simulate setting SSID and Password
    wifi.connect("example_wifi", "example_pass");
    return true;
}

int main(int argc, char* args[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!initSDL(&window, &renderer)) {
        SDL_Quit();
        return -1;
    }

    // Load font
    TTF_Font* font = TTF_OpenFont("resources/Arial.ttf", 16);
    if (font == nullptr) {
        SDL_Log("Failed to load font! SDL_ttf Error: %s", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    Emulator emulator;
    HUD hud;
    WiFi wifi;

    // Create Emulator
    if (!emulator.init()) {
        SDL_Log("Failed to initialize Emulator.");
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    bool quit = false;
    SDL_Event e;

    // Show WiFi Settings Dialog
    showWiFiSettings(renderer, wifi, font);

    // Update HUD with initial WiFi status
    hud.updateWiFiStatus(wifi.isConnected(), wifi.getSignalStrength());

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT)
                quit = true;
            // Handle other events (keyboard, etc.) here
        }

        // Emulation step
        wifi.optimizedStep();
        emulator.step();
        emulator.render(renderer);

        // Update HUD
        hud.updateWiFiStatus(wifi.isConnected(), wifi.getSignalStrength());
        hud.draw(renderer, font);

        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    // Clean up
    TTF_CloseFont(font);
    emulator.cleanUp();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}// Emulator.cpp
#include "Emulator.h"

Emulator::Emulator() {
    // Initialize emulator components
}

Emulator::~Emulator() {
    cleanUp();
}

bool Emulator::init() {
    // Initialize CPU, GPU, Memory, etc.
    return true;
}

void Emulator::step() {
    // Perform emulation steps (CPU cycles, GPU rendering, etc.)
    // Placeholder: simulate processing delay
}

void Emulator::render(SDL_Renderer* renderer) {
    // Render emulator screen
    // Placeholder: clear screen with a color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
    SDL_RenderClear(renderer);

    // Here you would render the emulator's framebuffer to the screen
    // For demonstration, we'll render a simple rectangle
    SDL_Rect fillRect = { 100, 100, 200, 150 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
    SDL_RenderFillRect(renderer, &fillRect);
}

void Emulator::cleanUp() {
    // Clean up emulator components
}
