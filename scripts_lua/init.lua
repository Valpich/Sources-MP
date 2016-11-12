uart.setup(0,115200,8,1,1)
print("Salut Romain !")

local SSID = "iPhone"
local SSID_PASSWORD = "codewifi"

wifi.setmode(wifi.STATION)
wifi.sta.config(SSID,SSID_PASSWORD)
wifi.sta.autoconnect(1)

function main()
    -- A timer alarm is sued to check if an IMAP reply has been processed
     print("main")
end

tmr.alarm(1, 1000, 1, function()
    pin = 1
    gpio.mode(pin, gpio.OUTPUT)
    if (gpio.read(pin) == 1) then
    gpio.write(pin, gpio.LOW)
    end
    if wifi.sta.status() ~= 5 then
        print("En attente de connexion ...")
    else
        print("Connexion OK avec l'IP: " .. wifi.sta.getip())
     if (gpio.read(pin) == 0) then
     gpio.write(pin, gpio.HIGH)
     end
        main()
        tmr.stop(1)
    end
end)
