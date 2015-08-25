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
 */
 
void setup() {
  Serial.begin(9600);
  delay(100); 
  // 複数寄生し，各寄生機器が存在を主張する場合は
  // 混信を防ぐため，タイミングをずらすこと
  Serial.println("I'm a parasite.");
}

void loop() {
  if (Serial.available()) 
    Serial.write(Serial.read());
}
