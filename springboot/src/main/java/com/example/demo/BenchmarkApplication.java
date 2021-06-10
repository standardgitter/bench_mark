package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@SpringBootApplication
public class BenchmarkApplication {

	public static void main(String[] args) {
		SpringApplication.run(BenchmarkApplication.class, args);
	}

	@RequestMapping(value = "/",produces = "text/plain;charset=UTF-8")
	String index(){
		return "Hello spring boot!";
	}
}
