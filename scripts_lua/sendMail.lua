require("base64")

local MY_EMAIL = "mpmicropro@aol.fr"
local EMAIL_PASSWORD = "maileseo"
local SMTP_SERVER = "smtp.aol.com"
local SMTP_PORT = "587"

local mail_to = "zetafr@gmail.com"

local email_subject = ""
local email_body = ""
local count = 0
local smtp_socket = nil 


-- Send Mail

function display(sck,response)
     print(response)
end


function do_next()
            if(count == 0)then
                count = count+1
                local IP_ADDRESS = wifi.sta.getip()
                smtp_socket:send("HELO "..IP_ADDRESS.."\r\n")
            elseif(count==1) then
                count = count+1
                smtp_socket:send("AUTH LOGIN\r\n")
            elseif(count == 2) then
                count = count + 1
                smtp_socket:send(base64.enc(MY_EMAIL).."\r\n")
            elseif(count == 3) then
                count = count + 1
                smtp_socket:send(base64.enc(EMAIL_PASSWORD).."\r\n")
            elseif(count==4) then
                count = count+1
               smtp_socket:send("MAIL FROM:<" .. MY_EMAIL .. ">\r\n")
            elseif(count==5) then
                count = count+1
               smtp_socket:send("RCPT TO:<" .. mail_to ..">\r\n")
            elseif(count==6) then
                count = count+1
               smtp_socket:send("DATA\r\n")
            elseif(count==7) then
                count = count+1
                local message = string.gsub(
                "From: \"".. MY_EMAIL .."\"<"..MY_EMAIL..">\r\n" ..
                "To: \"".. mail_to .. "\"<".. mail_to..">\r\n"..
                "Subject: ".. email_subject .. "\r\n\r\n"  ..
                email_body,"\r\n.\r\n","")
                
                smtp_socket:send(message.."\r\n.\r\n")
            elseif(count==8) then
               count = count+1
                 tmr.stop(0)
                 smtp_socket:send("QUIT\r\n")
            else
               smtp_socket:close()
            end
end


function connected(sck)
    tmr.alarm(0,5000,1,do_next)
end

function send_email(address,subject,body)
     print("Envoie du mail")
     gpio.mode(1, gpio.OUTPUT)
     gpio.write(1, gpio.HIGH)
     count = 0
     mail_to = address
     email_subject = subject
     email_body = body
     smtp_socket = net.createConnection(net.TCP,0)
     smtp_socket:on("connection",connected)
     smtp_socket:on("receive",display)
     smtp_socket:connect(SMTP_PORT,SMTP_SERVER)
end

print("Dans sendMail")