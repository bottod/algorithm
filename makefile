default:
	@g++ bigdata.cpp -o bigdata
	@g++ sortKc.cpp -o sortKc
clean:
	@rm -rf bigdata
	@rm -rf sortKc
