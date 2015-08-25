/*
 * PCとのUSB接続を1つのポートにまとめるためのスケッチ
 * 1つの"host"機器と複数の"parasite"機器で構成する
 * PCからのシリアル信号はそのまま全機器のRxへ流れる
 * parasite機器からのシリアル通信はhost機器のソフトウェアシリアルRxへ送信される
 * host機器はソフトウェアシリアルのバッファをそのままPCへ転送する
 * 
 * host,parasiteの全てのRxは短絡される
 * parasiteの全てのTxはhostのソフトウェアシリアルRxに接続される
 * 送受信機器について転送レートを同一にする
 * 
 * シリアルTxはデフォルトでHIGH(5V)なので，LOWだけ伝達する
 * 複数寄生する場合は，パラサイト側をカソードとして小信号用ダイオードを設置する
 * ホスト側（アノードの先）をプルアップする必要がある（？）
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // (rx, tx)

void setup()  {
  Serial.begin(9600);
  Serial.println("Goodnight moon!");

  // SoftwareSerialのポートを設定
  mySerial.begin(9600);
  // mySerial.println("Hello, world?");
}

void loop() {
  if (mySerial.available())
    Serial.write(mySerial.read());
}
