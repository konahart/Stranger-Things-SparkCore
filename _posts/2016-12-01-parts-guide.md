---
title:        "Parts Guide"
description:  "Detailed description of the parts you will need"
author:       "konahart"
---

Unless you have done other projects with light strings before, you probably do not have these parts sitting around. Without knowing more about what is needed for the project, it can be hard to know what to get. Below, I describe the hardware requirements. You can just buy the same parts I did, or shop around for better deals.

## Shopping list
 - Lights
 - Power supply for lights
 - Power supply jack adapters for lights
 - Microcontroller
 - Power supply for microcontroller

## Lights
In order to work for this project, the string of lights you use must have a few key characteristics: they must be **RGB** and **addressable**. This means that most Christmas lights you buy off the shelf will not really work for this project -- although they may be LEDs, they are not generally addressable. If you were hoping to reuse some old Christmas lights: sorry!

["Arduino Based Stranger Things Lights"](http://www.instructables.com/id/Arduino-Based-Stranger-Things-Lights) recommended [Mokungit 100pcs WS2811 12mm LEDs](https://www.amazon.com/gp/product/B01DLVK3CE/), and that is what I used, too. Other lights can work just as well, too. When shopping for lights like these, the product names can be somewhat cryptic at first; for example, the full name for the one linked is currently “*Mokungit 100pcs WS2811 12mm DC5V Input Diffused Digital RGB Wire Cable LED Pixels Module String Light IP68 Waterproof Addressable Dream Color Pixels Exposed Light String.*” 

Let's break that down a bit.

- **Mokungit** : the brand. This does not matter much, though I can tell you that the Mokungit lights I got worked fine.
- **100 pcs** : includes 100 LEDs, sometimes referred to as “pixels” in this context. Actually, this includes 2 strings of 50 LEDs -- you will have to connect these yourself. I will detail that below. Because of the alphabetical nature of the project, only 26 lights are really required. However, the more strings of lights you include, the bigger the letters and overall display can be. 
- **WS2811** : refers to the LEDs' chipset --- basically, how it communicates with the microprocessor. Other chipsets can be used, too! We will be using the [FastLED library](https://github.com/FastLED/FastLED) to drive the lights, so I recommend using the [Chipset Reference](https://github.com/FastLED/FastLED/wiki/Chipset-reference) to select compatible lights. 
- **12mm** : the size of the LEDs. 
- **DC5V** : the type and amount of electricity required to power the lights. When buying a power supply for the lights, be sure that the lights and power supply have the same description. 
- **RGB** : stands for Red, Green, Blue. When we program the lights, all the colors will be described as combinations of these three colors. This is how the display on your computer works, too!
- **LED Pixels** : the lights are LEDs, or Light Emitting Diodes. 
- **IP68 Waterproof** : the weather proofing/waterproofing rating. You should look into this if you want to make an outdoor installation, but generally is not worth worrying about for an indoor display. 
- **Addressable** : the lights on the string can be controlled individually, rather than all-or-nothing like most Christmas lights.

The rest of the product title (“Input Diffused Digital,” “Wire Cable,” “Pixels Module String Light,” “Dream Color Pixels Exposed Light String”) are just additional keywords to help the product show up in more searches.

Again, many of these aspects can be changed and still be usable for this project. The defining characteristics you should look for are that they are **RGB** and **addressable**. If you buy different lights, you may need to change some parts at the top of the Spark Core script. 

##Power supply for lights
Unlike most electronics, LED strings do not always come with a way to power them. Exactly what kind of power supply you need will depend on the lights you get. The important part to determine this is the "DC5V" part. The lights will probably either be 5V or 12V; it should be in the product description. When buying a power supply for the lights, just be sure that part matches. 

[The one I bought](https://www.amazon.com/Mokungit-Plastic-Adapter-Charger-Transformers/dp/B01EAF4YP2) is the same brand as the lights, but it probably does not matter that much.

## Power supply jack adapters for lights
Strangely (to me), in addition to being sold separately from a power supply, LED strings also do not come with a way to plug them in right out of the box. In the [Setup Instructions](/2016/11/19/setup-instructions/) I detail how to wire the parts together. 

Strictly speaking, only 1 female adapter is needed to connect to the power supply's male adapter, but it is hard to even find individual adapters to buy, and they are not that expensive anyway. [The set I bought](https://www.amazon.com/Maxmoral-Female-Power-5-5mm-Adapter/dp/B00XJ23U3A) came with 5 male and 5 female adapters. I ended up using 2 of each, and it is kind of nice to know that if I want to expand my light string, all I need to get is the lights; I am all set for power and adapters. 

## Microcontoller
This is one of very few places I parted with the advice of ["Arduino Based Stranger Things Lights"](http://www.instructables.com/id/Arduino-Based-Stranger-Things-Lights) with regard to hardware.  Instead of an [Arduino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno), I used a Spark Core, since I already had a [Particle Maker Kit](https://store.particle.io/collections/photon). The two are very similar, and it probably even possible to reuse the same code. I have never used an Arduino, so I do not know if it has all the user-friendly features of the Spark Core, such as the Web IDE. It looks like Particle's current equivalent product is the [Photon](https://store.particle.io/collections/photon). 

## Power supply for microcontroller
As with powering the lights, the power supply for your microcontroller depends on which one you use. The Spark Core, Photon, and Electron are all powered using a Micro-USB cable, so if you have had a (non-Type-C) Android phone, you probably already have the cable and AC adapter you need. 

If you bought a new microcontroller, it probably came with whatever you need to power it. Just be sure you have a power supply available when you start the project.
