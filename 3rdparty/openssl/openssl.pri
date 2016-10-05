unix:android {
    LIBS_SSL_DIR=$$PWD/libs/$${ANDROID_TARGET_ARCH}

    INCLUDEPATH += \
        $$PWD/include

#    ANDROID_EXTRA_LIBS += $${LIBS_SSL_DIR}/libcrypto.so
#    ANDROID_EXTRA_LIBS += $${LIBS_SSL_DIR}/libssl.so
#    bundled_libs.files = \
#        $${LIBS_SSL_DIR}/libssl.so \
#        $${LIBS_SSL_DIR}/libcrypto.so

    LIBS += -L$${LIBS_SSL_DIR}
    LIBS += \
        -l$${LIBS_SSL_DIR}/libssl.a \
        -l$${LIBS_SSL_DIR}/libcrypto.a
}

unix:!android {
    LIBS += \
        -lssl \
        -lcrypto
}
