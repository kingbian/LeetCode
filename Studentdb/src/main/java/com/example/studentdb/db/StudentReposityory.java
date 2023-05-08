package com.example.studentdb.db;

import com.example.studentdb.model.Student;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface StudentReposityory extends CrudRepository <Student, Long> {

}
