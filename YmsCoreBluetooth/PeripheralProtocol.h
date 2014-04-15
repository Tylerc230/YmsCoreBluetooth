//
//  PeripheralProtocol.h
//  ZuliApp
//
//  Created by Tyler Casselman on 4/15/14.
//  Copyright (c) 2014 Zuli, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@protocol PeripheralProtocol <NSObject>
@property(weak, nonatomic) id<CBPeripheralDelegate> delegate;
@property(retain, readonly) NSString *name;
- (NSUUID *)identifier;
- (CBPeripheralState)state;
- (void)discoverServices:(NSArray *)serviceUUIDs;
- (void)discoverCharacteristics:(NSArray *)characteristicUUIDs forService:(id)service;
- (NSArray *)services;
- (void)writeValue:(NSData *)data forCharacteristic:(id)characteristic type:(CBCharacteristicWriteType)type;
- (void)readValueForCharacteristic:(id)characteristic;
- (void)setNotifyValue:(BOOL)enabled forCharacteristic:(id)characteristic;
- (void)discoverDescriptorsForCharacteristic:(id)characteristic;
- (void)writeValue:(NSData *)data forDescriptor:(id)descriptor;
- (void)readValueForDescriptor:(id)descriptor;
- (NSNumber *)RSSI;
- (void)readRSSI;
@end
