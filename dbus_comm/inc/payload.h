/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   payload.h
 * Author: dfernandez
 *
 * Created on April 14, 2018, 11:24 AM
 */

#ifndef PAYLOAD_H
#define PAYLOAD_H

#define NAME_SIZE 20
#define ADDR_SIZE 100

typedef struct _mypayload {
    char name[NAME_SIZE];
    int age;
    char gender;
    char address[ADDR_SIZE];
} mypayload_t;

#endif /* PAYLOAD_H */

