from flask import Flask, request, render_template, redirect
import os
import serial
import time

app = Flask(__name__)
app.config["TEMPLATES_AUTO_RELOAD"] = True
arduino = serial.Serial(port="<serial port>",baudrate=9600)
time.sleep(3)
arduino.write("blue".encode())
time.sleep(2)

@app.route("/")
def index():
	return render_template("index.html")


@app.route("/red", methods=["POST"])
def red():
    arduino.write("red".encode())
    time.sleep(2)
    return redirect("/")

@app.route("/off", methods=["POST"])
def off():
    arduino.write("off".encode())
    time.sleep(2)
    return redirect("/")

@app.route("/blue", methods=["POST"])
def blue():
    arduino.write("blue".encode())
    time.sleep(2)
    return redirect("/")

@app.route("/green", methods=["POST"])
def green():
    arduino.write("green".encode())
    time.sleep(2)
    return redirect("/")

@app.route("/white",methods=["POST"])
def white():
    arduino.write("white".encode())
    time.sleep(2)
    return redirect("/")


@app.route("/yellow",methods=["POST"])
def yellow():
    arduino.write("yellow".encode())
    time.sleep(2)
    return redirect("/")

@app.route("/mobile")
def mobile():
    return render_template("mobile.html",color="#FF0000")

@app.route("/mobilegreen",methods=["POST"])
def mobilegreen():
    arduino.write("green".encode())
    time.sleep(2)
    return render_template("mobile.html",color="#00FF00")


@app.route("/rainbow",methods=["POST"])
def rainbow():
    arduino.write("rainbow".encode())
    time.sleep(2)
    return redirect("/")

@app.route("/whiteflow",methods=["POST"])
def whiteflow():
    arduino.write("whiteflow".encode())
    time.sleep(2)
    return redirect("/")
