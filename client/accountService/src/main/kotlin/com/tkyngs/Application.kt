package com.tkyngs

import io.ktor.server.engine.*
import io.ktor.server.netty.*
import com.tkyngs.plugins.*

fun main() {
  embeddedServer(Netty, port = 8080, host = "0.0.0.0") {
    configureRouting()
    configureSecurity()
    configureHTTP()
    configureTemplating()
    configureSerialization()
  }.start(wait = true)
}
