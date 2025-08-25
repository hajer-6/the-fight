FROM gcc:11 

WORKDIR /app

COPY . /app

RUN g++ -std=c++11 fight.cpp character.cpp weapon.cpp -o battle

CMD ["./battle"]
