package com.example.studentdb.service;

import com.example.studentdb.db.StudentReposityory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class StudentService {

    @Autowired
    private StudentReposityory studentRepo;

}
