package com.example.demo;

import com.github.benmanes.caffeine.cache.Cache;
import com.github.benmanes.caffeine.cache.Caffeine;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.util.StopWatch;

import java.util.concurrent.TimeUnit;

@SpringBootApplication
public class CaffinebanchmarkApplication {

	public static void main(String[] args) {
		SpringApplication.run(CaffinebanchmarkApplication.class, args);
		System.out.println("caffeine benchmark");

		Cache<String, Object> cache = Caffeine.newBuilder()
				.expireAfterWrite(1, TimeUnit.DAYS)
				.maximumSize(999999999)
				.build();

		cache.put("key1", "value1");
		System.out.println(cache.getIfPresent("key1"));
		cache.invalidate("key1");

		int num=3000000;
		StopWatch watch = new StopWatch();
		watch.start("watcher");
		int i;
		for(i=0;i<num;i++){
			cache.put("k"+i, "v"+i);
		}

		watch.stop();

		System.out.println("insert "+num+" item  in "+watch.getTotalTimeSeconds()+" seconds, "+ num/watch.getTotalTimeMillis()*1000 + "insert/second");
	}



}
