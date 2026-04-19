import { Component, signal } from '@angular/core';
import { RouterOutlet } from '@angular/router';
@Component({
selector: 'app-root',
imports: [RouterOutlet],
templateUrl: 'app.html',
styleUrl: 'app.css'
})
export class App {
  name: string = 'Angular';
  age: number = 20;
  email: string = 'anu@gmail.com';
}