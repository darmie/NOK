import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { GameView } from './lib/GameView';
import { Framebuffer } from './lib/Framebuffer';
import { Color } from './lib/Graphics/Color';

export default function App() {
  return (
      <GameView style={styles.container} draw={(framebuffer: Framebuffer) => {
        const g = framebuffer.g4;
        g.begin()
        g.clear(Color.fromFloats(0.0, 0.0, 0.3), 0.6)
        g.end() 
      }} width={600} height={600} /> 
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: 'transparent',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
