cmake_minimum_required(VERSION 3.23)
project(competitive-programming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3")

include_directories(/usr/local/include)

set(LETTERS "A" "B" "C" "D" "E" "F" "G" "H" "I" "J" "K" "L" "M" "N")
list(APPEND LETTERS "O" "P" "Q" "R" "S" "T" "U" "V" "W" "X" "Y" "Z")

set(STRUCTURE "F D H E D F G E")
list(APPEND STRUCTURE "D J E C G F K H G L")

list(LENGTH LETTERS letters_len)
list(LENGTH STRUCTURE semester_quantity)
math(EXPR semester_quantity "${semester_quantity} - 1")

foreach (semester_number RANGE ${semester_quantity})
    list(GET STRUCTURE ${semester_number} semester)
    math(EXPR semester_number "${semester_number} + 1")
    set(contest_number 1)
    separate_arguments(contests UNIX_COMMAND "${semester}")
    foreach (contest_last_letter ${contests})
        set(letter_number 0)
        list(GET LETTERS ${letter_number} letter)
        while ((${contest_last_letter} STRGREATER_EQUAL ${letter}) AND (${letter_number} LESS ${letters_len}))
            string(TOLOWER ${letter} lowercase_letter)
            set(FILE_PATH "Semester-${semester_number}/Contest-${contest_number}/Problem-${letter}")

            if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${FILE_PATH}/solution.cpp)
                file(READ ${FILE_PATH}/solution.cpp file_content)
                if ("${file_content}" STREQUAL "")
                    configure_file(
                            ${CMAKE_CURRENT_SOURCE_DIR}/templates/template.cpp
                            ${CMAKE_CURRENT_SOURCE_DIR}/${FILE_PATH}/solution.cpp COPYONLY
                    )
                endif ()
                unset(file_content)
            else ()
                configure_file(
                        ${CMAKE_CURRENT_SOURCE_DIR}/templates/template.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/${FILE_PATH}/solution.cpp COPYONLY
                )
            endif ()
            set(is_readme TRUE)
            if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${FILE_PATH}/README.md)
                file(READ ${FILE_PATH}/README.md file_content)
                if ("${file_content}" STREQUAL "")
                    set(is_readme FALSE)
                endif()
            else()
                set(is_readme FALSE)
            endif()
            if ("${is_readme}" STREQUAL FALSE)
                configure_file(
                        ${CMAKE_CURRENT_SOURCE_DIR}/templates/README.md
                        ${CMAKE_CURRENT_SOURCE_DIR}/${FILE_PATH}/README.md COPYONLY
                )
            endif ()
            if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${FILE_PATH}/input.txt)
                file(WRITE ${FILE_PATH}/input.txt "")
            endif ()

            set(TARGET_NAME comp-${semester_number}-${contest_number}-${lowercase_letter})
            math(EXPR letter_number "${letter_number} + 1")
            list(GET LETTERS ${letter_number} letter)
            add_executable(${TARGET_NAME} ${FILE_PATH}/solution.cpp)
            set(INPUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${FILE_PATH}/input.txt)
            file(READ ${INPUT_FILE} file_content)
            if (NOT "${file_content}" STREQUAL "")
                set_target_properties(${TARGET_NAME} PROPERTIES COMPILE_DEFINITIONS INPUT_FILE="${INPUT_FILE}")
            endif ()
            unset(file_content)
        endwhile ()
        math(EXPR contest_number "${contest_number} + 1")
    endforeach ()
    unset(contest_number)
endforeach ()
