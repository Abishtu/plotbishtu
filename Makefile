
pull:
	git pull

configure:
	cd build && cmake ../

run: run
	bin/plotbishtu

build: configure
	cd build && cmake --build . && mv plotbishtu ../bin/plotbishtu

clean:
	rm bin/* && rm debug/*
