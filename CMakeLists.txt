cmake_minimum_required(VERSION 3.16)

# Inclui as ferramentas do ESP-IDF
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Build minimal
idf_build_set_property(MINIMAL_BUILD ON)

# Nome do projeto
project(conexao_mic)
