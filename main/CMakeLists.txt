idf_component_register(SRCS "main.cpp"
                            "Led.cpp"
                            "gpioESP32.cpp"
                            "Button.cpp"
                            "gpioDefinition.c"
                            "ButtonManager.cpp"
                            "BLEMidiESP32.cpp"
                    INCLUDE_DIRS "./Inc/"
                    REQUIRES blemidi)
