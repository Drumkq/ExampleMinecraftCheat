cmake_minimum_required(VERSION 3.6.0)

FILE (GLOB MH_srcs
    *.c
    *.h
    hde/*.c
    hde/*.h
)

target_sources(Wercilius PRIVATE
    ${MH_srcs}
)
