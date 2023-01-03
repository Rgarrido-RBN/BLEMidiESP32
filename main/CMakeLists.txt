idf_component_register(SRC_DIRS     "src/ble/"
                                    "src/button/"
                                    "src/gpio/"
                                    "src/led/"
                                    "src/uart/"
                                    "src/midi/"
                                    "."

                       INCLUDE_DIRS "./Inc/"

                       REQUIRES     blemidi
                                    uartmidi
                      )
